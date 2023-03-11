//! by wy_xx123:please don't copy

#include "ramfs.h"
/* modify this file freely */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// * my define
#define FILES_OPEN_MAX 5000 // ! more?
#define MAX_LEN_NAME 33
#define DEBUG_MAX_LEN (MAX_LEN_NAME - 1)
#define DEFAULT_INITIAL_FILE_SIZE 0

#define O_WRABLE 03

typedef enum type
{
	t_dir,
	t_file,
} TYPE;

typedef enum find_type
{
	t_add,
	t_del,
} FT;

typedef struct file
{
	char* pf;
	ssize_t size;
	char name[MAX_LEN_NAME];
	struct file* next;
} MY_FILE;

typedef struct open_file
{
	int flag;
	off_t offset;
	MY_FILE* p_m_f;
	TYPE type;
} OPEN_FILE;

OPEN_FILE* files[FILES_OPEN_MAX] = { 0 };

typedef struct dir DIR;

typedef struct page
{
	DIR* head_dir;
	MY_FILE* head_file;
} PAGE;

typedef struct dir
{
	char name[MAX_LEN_NAME];
	PAGE* page;
	struct dir* next;
} DIR;

typedef struct ramf
{
	PAGE* root;
} RAMF;
RAMF ramf;
DIR* root_dir = NULL;

void CreatFile(PAGE* cur, const char* tmp_name);
void AddSize(MY_FILE* file, size_t size);
void* FindFileOrDir(TYPE* type, const char* pathname, FT find_type, int* index, PAGE** page);
bool IsDirEmpty(const DIR* address);
bool IsArrayError(const char* pathname);
int FindFirstEmptyFile(void);

// * my define

void init_ramfs()
{
	ramf.root = malloc(sizeof(PAGE));
	ramf.root->head_dir = NULL;
	ramf.root->head_file = NULL;
	root_dir = malloc(sizeof(DIR));
	root_dir->page = ramf.root;
}

int ropen(const char* pathname, int flags)
{
	PAGE* cur = ramf.root;
	int pointer_index = 0;

	if (IsArrayError(pathname))
		return -1;

	if (*pathname != '/')
		return -1;

	bool is_first_time = true;
	while (1)
	{
		if (pathname[pointer_index] == '/')
			while (pathname[(pointer_index++) + 1] == '/');
		if (pathname[pointer_index] == '\0' && is_first_time == false)
			return -1;

		int pc = pointer_index;
		while (pathname[pc] != '/' && pathname[pc] != '\0')
			pc++;
		int size = pc - pointer_index;
		char* tmp_name = malloc(size + 1);
		strncpy(tmp_name, pathname + pointer_index, size);
		tmp_name[size] = '\0';
		pointer_index = pc;

		if (size > DEBUG_MAX_LEN)
			return -1;

		//file
		MY_FILE* cur_file = cur->head_file;
		while (cur_file != NULL)
		{
			if (cur_file != NULL && !strcmp(tmp_name, cur_file->name))
			{
				if (pathname[pc] != '\0') // ? have '\0' or not?
				{
					free(tmp_name);
					return -1;
				}

				if ((flags & O_TRUNC) && (flags & O_WRABLE))
				{
					// version1: don't free.
					//memset(cur->file[i]->pf, 0, cur->file[i]->size);

					// version2: free
					free(cur_file->pf);
					cur_file->pf = NULL;
					cur_file->size = 0;
				}

				int count_file = FindFirstEmptyFile();

				files[count_file] = malloc(sizeof(OPEN_FILE));
				files[count_file]->p_m_f = cur_file;
				files[count_file]->flag = flags;
				files[count_file]->offset =
					(flags & O_APPEND) ? (off_t)cur_file->size : 0;
				files[count_file]->type = t_file;

				free(tmp_name);
				return count_file;
			}
			cur_file = cur_file->next;
		}



		//dir
		bool should_continue = false;
		DIR* cur_dir = cur->head_dir;

		if (is_first_time && strlen(tmp_name) == 0)
		{
			int count_file = FindFirstEmptyFile();
			files[count_file] = malloc(sizeof(OPEN_FILE));
			files[count_file]->type = t_dir;
			free(tmp_name);
			return count_file;
		}

		while (cur_dir != NULL)
		{
			if (cur_dir != NULL && !strcmp(tmp_name, cur_dir->name))
			{
				int tmp_index = pc;
				while (pathname[tmp_index] == '/')
					tmp_index++;
				if (pathname[tmp_index] != '\0')
				{
					pointer_index = tmp_index;
					cur = cur_dir->page;
					is_first_time = false;
					should_continue = true;
				}
				else
				{
					int count_file = FindFirstEmptyFile();
					files[count_file] = malloc(sizeof(OPEN_FILE));
					files[count_file]->type = t_dir;
					free(tmp_name);
					return count_file;
				}
			}
			cur_dir = cur_dir->next;
		}
		if (should_continue)
		{
			free(tmp_name);
			continue;
		}

		//make file
		if ((flags & O_CREAT) && pathname[pc] == '\0')
		{
			CreatFile(cur, tmp_name);
			int count_file = FindFirstEmptyFile();
			files[count_file] = malloc(sizeof(OPEN_FILE));

			files[count_file]->offset =
				(flags & O_APPEND) ? (off_t)cur->head_file->size : 0;
			files[count_file]->p_m_f = cur->head_file;
			files[count_file]->flag = flags;
			files[count_file]->type = t_file;

			free(tmp_name);
			return count_file;
		}

		free(tmp_name);
		return -1; // ! really?


	}
}

int rclose(int fd)
{
	if (fd < 0 || fd >= FILES_OPEN_MAX || files[fd] == NULL)
		return -1;

	free(files[fd]);
	files[fd] = NULL;
	return 0;
}

off_t rseek(int fd, off_t offset, int whence)
{
	if (fd < 0 || fd >= FILES_OPEN_MAX || files[fd] == NULL || files[fd]->type == t_dir)
		return -1;

	OPEN_FILE* tmp_file = files[fd];
	if (whence == SEEK_SET)
		tmp_file->offset = offset;
	else if (whence == SEEK_CUR)
		tmp_file->offset += offset;
	else
		tmp_file->offset = (off_t)(tmp_file->p_m_f->size + offset);

	if (tmp_file->offset < 0)
		return -1;

	return tmp_file->offset;
}

ssize_t rwrite(int fd, const void* buf, size_t count)
{
	if (fd < 0 || fd >= FILES_OPEN_MAX || files[fd] == NULL || files[fd]->type == t_dir)
		return -1;

	OPEN_FILE* tmp_file = files[fd];
	if (!(tmp_file->flag & O_WRABLE))
		return -1;

	if (tmp_file->offset + count > tmp_file->p_m_f->size)
		AddSize(tmp_file->p_m_f, tmp_file->offset + count);


	memcpy(tmp_file->p_m_f->pf + tmp_file->offset, buf, count);
	rseek(fd, (off_t)count, SEEK_CUR);

	return (ssize_t)count;
}

ssize_t rread(int fd, void* buf, size_t count)
{
	if (fd < 0 || fd >= FILES_OPEN_MAX || files[fd] == NULL || files[fd]->type == t_dir || files[fd]->flag & O_WRONLY)
		return -1;

	const OPEN_FILE* tmp_file = files[fd];
	size_t left = tmp_file->p_m_f->size - tmp_file->offset;
	size_t read_size = (left > count) ? count : left;
	//version 0 : for:
	// 	for (size_t i = 0; i < read_size; i++)
	//		((char*)buf)[i] = tmp_file->p_m_f->pf[tmp_file->offset + i];

	//version 1 : memcpy
	memcpy(buf, tmp_file->p_m_f->pf + tmp_file->offset, read_size);

	rseek(fd, (off_t)read_size, SEEK_CUR);
	return (read_size > 0) ? (ssize_t)read_size : 0;
}

int rmkdir(const char* pathname)
{
	if (IsArrayError(pathname))
		return -1;

	int size = (int)strlen(pathname);
	char* tmp_pathname = malloc(size);
	memset(tmp_pathname, 0, size);
	strncpy(tmp_pathname, pathname, size);

	int pi = size - 1;
	while (tmp_pathname[pi] == '/')
		pi--;

	int prev = pi;
	while (tmp_pathname[prev] != '/')
		prev--;

	int dir_name_len = pi - prev + 1;
	char* dir_name = malloc(dir_name_len);
	strncpy(dir_name, tmp_pathname + prev + 1, dir_name_len);
	dir_name[dir_name_len - 1] = '\0';

	if (dir_name_len - 1 > DEBUG_MAX_LEN)
	{
		free(tmp_pathname);
		free(dir_name);
		return -1;
	}

	memset(tmp_pathname + prev + 1, 0, size - prev - 1);

	TYPE type = 0;
	int index = 0;
	PAGE* page = NULL;
	const DIR* address = FindFileOrDir(&type, tmp_pathname, t_add, &index, &page);
	if (!address || type == t_file)
	{
		free(tmp_pathname);
		free(dir_name);
		return -1;
	}

	DIR* cur_dir = address->page->head_dir;
	while (cur_dir != NULL)
	{
		if (cur_dir != NULL && !strcmp(cur_dir->name, dir_name))
		{
			free(tmp_pathname);
			free(dir_name);
			return -1;
		}
		cur_dir = cur_dir->next;
	}

	DIR* dir = malloc(sizeof *dir);
	memset(dir->name, 0, MAX_LEN_NAME);
	strncpy(dir->name, dir_name, dir_name_len);
	dir->page = malloc(sizeof(PAGE));
	dir->page->head_file = NULL;
	dir->page->head_dir = NULL;

	dir->next = address->page->head_dir;
	address->page->head_dir = dir;

	free(tmp_pathname);
	free(dir_name);

	return 0;
}

int rrmdir(const char* pathname)
{
	if (IsArrayError(pathname))
		return -1;

	TYPE type = 0;
	int index = 0;
	PAGE* page = NULL;
	DIR* address = FindFileOrDir(&type, pathname, t_del, &index, &page);
	if (!address || type == t_file || !IsDirEmpty(address))
		return -1;

	if (index == 0)
		page->head_dir = page->head_dir->next;
	else
	{
		DIR* prev_del = page->head_dir;
		for (int i = 0; i < index - 1; i++)
			prev_del = prev_del->next;
		prev_del->next = address->next;
	}

	free(address->page);
	free(address);
	return 0;
}

int runlink(const char* pathname)
{
	if (IsArrayError(pathname))
		return -1;

	TYPE type = 0;
	int index = 0;
	PAGE* page = NULL;
	MY_FILE* address = FindFileOrDir(&type, pathname, t_del, &index, &page);
	if (!address || type == t_dir)
		return -1;

	if (index == 0)
		page->head_file = page->head_file->next;
	else
	{
		MY_FILE* prev_del = page->head_file;
		for (int i = 0; i < index - 1; i++)
			prev_del = prev_del->next;
		prev_del->next = address->next;
	}

	// ! potential bug: w/r files through "fd" after the file is free
	free(address->pf);
	free(address);
	return 0;
}

void CreatFile(PAGE* cur, const char* tmp_name)
{
	MY_FILE* tmp_file = malloc(sizeof *tmp_file);
	strcpy(tmp_file->name, tmp_name);
	tmp_file->size = DEFAULT_INITIAL_FILE_SIZE;
	tmp_file->pf = NULL;

	tmp_file->next = cur->head_file;
	cur->head_file = tmp_file;
}

void AddSize(MY_FILE* file, size_t size)
{
	file->pf = realloc(file->pf, size);
	memset(file->pf + file->size, 0, size - file->size);
	file->size = (ssize_t)size;
}

void* FindFileOrDir(TYPE* type, const char* pathname, FT find_type, int* index, PAGE** page)
{
	PAGE* cur = ramf.root;
	int pointer_index = 0;
	bool is_first_time = true;

	if (*pathname != '/')
		return NULL;

	while (1)
	{
		if (pathname[pointer_index] == '/')
			while (pathname[(pointer_index++) + 1] == '/');
		if (pathname[pointer_index] == '\0')
		{
			if (find_type == t_del)
				return NULL;

			if (is_first_time)
			{
				*page = cur;
				*type = t_dir;
				return root_dir;
			}
		}

		int pc = pointer_index;
		while (pathname[pc] != '/' && pathname[pc] != '\0')
			pc++;
		int size = pc - pointer_index;
		char* tmp_name = malloc(size + 1);
		strncpy(tmp_name, pathname + pointer_index, size);
		tmp_name[size] = '\0';
		pointer_index = pc;

		if (size > DEBUG_MAX_LEN)
			return NULL;

		//file
		MY_FILE* cur_file = cur->head_file;
		int file_index = 0;
		while (cur_file != NULL)
		{
			if (cur_file != NULL && !strcmp(tmp_name, cur_file->name))
			{
				if (pathname[pc] != '\0') // ? !
				{
					free(tmp_name);
					return NULL;
				}

				*index = file_index;
				*type = t_file;
				*page = cur;
				free(tmp_name);
				return cur_file;
			}

			file_index++;
			cur_file = cur_file->next;
		}


		//dir
		bool should_continue = false;
		int dir_index = 0;
		DIR* cur_dir = cur->head_dir;
		while (cur_dir != NULL)
		{
			if (cur_dir != NULL && !strcmp(tmp_name, cur_dir->name))
			{
				int tmp_index = pc;
				while (pathname[tmp_index] == '/')
					tmp_index++;
				if (pathname[tmp_index] != '\0')
				{
					pointer_index = tmp_index;
					cur = cur_dir->page;
					is_first_time = false;
					should_continue = true;
				}
				else
				{
					*type = t_dir;
					*index = dir_index;
					*page = cur;
					free(tmp_name);
					return cur_dir;
				}
			}
			cur_dir = cur_dir->next;
			dir_index++;
		}

		if (should_continue)
		{
			free(tmp_name);
			continue;
		}

		free(tmp_name);
		return NULL;
	}
}

bool IsDirEmpty(const DIR* address)
{
	if (address->page->head_file == NULL && address->page->head_dir == NULL)
		return true;
	return false;
}

bool IsArrayError(const char* pathname)
{
	int size = (int)strlen(pathname);
	for (int i = 0; i < size; i++)
		if ((pathname[i] < 'a' || pathname[i] > 'z')
			&& (pathname[i] < 'A' || pathname[i] > 'Z')
			&& (pathname[i] < '0' || pathname[i] > '9')
			&& pathname[i] != '.' && pathname[i] != '/')
			return true;
	return false;
}

int FindFirstEmptyFile(void)
{
	for (int i = 0; i < FILES_OPEN_MAX; i++)
		if (files[i] == NULL)
			return i;
	exit(-1);
}


