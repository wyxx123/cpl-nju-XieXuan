//
// Created by xiexu on 2022/12/9.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NAME_LEN 15
#define MAX_NUM_OF_FILE 10010

typedef struct my_file
{
	char name[NAME_LEN];
	int num_of_files;
	int index_file1;
	int index_file2;
} MyFile;

int count_files = 0;
MyFile files[MAX_NUM_OF_FILE] = { 0 };

bool MakeFile(char* new_file, char* father_file, int index);
int FindIndex(char* oped_file);
int RemoveFile(char* oped_file, int range_file_index);

int main(void)
{
	int n = 0;
	int q = 0;
	scanf("%d%d", &n, &q);

	//make files
	for (int i = 0; i < n; i++)
	{
		char new_file[FILENAME_MAX] = { 0 };
		char father_file[FILENAME_MAX] = { 0 };
		scanf("%s%s", new_file, father_file);

		if (father_file[0] == '~')
		{
			strcpy(files[0].name, new_file);
		}
		else
			MakeFile(new_file, father_file, 0);

		count_files++;
	}

	//op
	for (int i = 0; i < q; i++)
	{
		char option[NAME_LEN] = { 0 };
		char oped_file[NAME_LEN] = { 0 };
		scanf("%s%s", option, oped_file);

		int file_index = 0;
		switch (*option)
		{
		case 'q':
			file_index = FindIndex(oped_file);
			printf("%d\n", files[file_index].num_of_files + 1);
			break;
		case 'r':
			RemoveFile(oped_file, 0);
			break;
		default:
			printf("wy_xx123:err\n");
		}
	}
	return 0;
}

bool MakeFile(char* new_file, char* father_file, int index)
{
//	printf("%d\n", index);

	if (strcmp(father_file, files[index].name) == 0)
	{
		strcpy(files[count_files].name, new_file);
		if (files[index].index_file1 == 0)
		{
			files[index].index_file1 = count_files;
			files[index].num_of_files++;
			return true;
		}

		files[index].index_file2 = count_files;
		files[index].num_of_files++;
		return true;
	}

	if (files[index].index_file1 != 0 &&
		MakeFile(new_file, father_file, files[index].index_file1))
	{
		files[index].num_of_files++;
		return true;
	}

	if (files[index].index_file2 != 0 &&
		MakeFile(new_file, father_file, files[index].index_file2))
	{
		files[index].num_of_files++;
		return true;
	}

	return false;
}

int FindIndex(char* oped_file)
{
	for (int i = 0; i < count_files; i++)
	{
		if (strcmp(oped_file, files[i].name) == 0)
			return i;
	}

	return -1;
}

bool should_delete = false;
int RemoveFile(char* oped_file, int range_file_index)
{
	if (strcmp(oped_file, files[range_file_index].name) == 0)
	{
		should_delete = true;
		return files[range_file_index].num_of_files + 1;
	}

	if (files[range_file_index].index_file1 != 0)
	{
		int delta_files = RemoveFile(oped_file, files[range_file_index].index_file1);
		if (delta_files != 0 && should_delete)
		{
			files[range_file_index].index_file1 = 0;
			should_delete = false;
			files[range_file_index].num_of_files -= delta_files;
			return delta_files;
		}

		if (delta_files != 0 && !should_delete)
		{
			files[range_file_index].num_of_files -= delta_files;
			return delta_files;
		}
	}

	if (files[range_file_index].index_file2 != 0)
	{
		int delta_files = RemoveFile(oped_file, files[range_file_index].index_file2);
		if (delta_files != 0 && should_delete)
		{
			files[range_file_index].index_file2 = 0;
			should_delete = false;
			files[range_file_index].num_of_files -= delta_files;
			return delta_files;
		}

		if (delta_files != 0 && !should_delete)
		{
			files[range_file_index].num_of_files -= delta_files;
			return delta_files;
		}
	}

	return 0;
}



