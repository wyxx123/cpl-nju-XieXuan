//
// Created by xiexu on 2022/11/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	//creation of array.
	char** pointer_to_row_array = malloc(n * sizeof(char*));
	assert(pointer_to_row_array != NULL);
	for (int i = 0; i < n; i++)
	{
		char* tmp_row_array = malloc(n * sizeof(char));
		assert(tmp_row_array != NULL);
		*(pointer_to_row_array + i) = tmp_row_array;
		memset(tmp_row_array, 0, n * sizeof(char));
		scanf("%101s", tmp_row_array);
	}

	int** pointer_to_each_condition_array = malloc(8 * sizeof(int*));
	assert(pointer_to_each_condition_array != NULL);
	for (int i = 0; i < 8; i++)
	{
		int* tmp_each_condition_array = malloc(2 * sizeof(int));
		*(pointer_to_each_condition_array + i) = tmp_each_condition_array;
		assert(tmp_each_condition_array != NULL);
	}

	//initialize the station array.
	*(*pointer_to_each_condition_array) = -1;
	*(*pointer_to_each_condition_array + 1) = -1;

	*(*(pointer_to_each_condition_array + 1)) = -1;
	*(*(pointer_to_each_condition_array + 1) + 1) = 0;

	*(*(pointer_to_each_condition_array + 2)) = -1;
	*(*(pointer_to_each_condition_array + 2) + 1) = 1;

	*(*(pointer_to_each_condition_array + 3)) = 0;
	*(*(pointer_to_each_condition_array + 3) + 1) = -1;

	*(*(pointer_to_each_condition_array + 4)) = 0;
	*(*(pointer_to_each_condition_array + 4) + 1) = 1;

	*(*(pointer_to_each_condition_array + 5)) = 1;
	*(*(pointer_to_each_condition_array + 5) + 1) = -1;

	*(*(pointer_to_each_condition_array + 6)) = 1;
	*(*(pointer_to_each_condition_array + 6) + 1) = 0;

	*(*(pointer_to_each_condition_array + 7)) = 1;
	*(*(pointer_to_each_condition_array + 7) + 1) = 1;

	//check zone.
	for (int i = 0; i < n; i++)
	{
		//print elements.
		for (int j = 0; j < n; j++)
		{
			// o
			if (*(*(pointer_to_row_array + i) + j) == '*')
			{
				printf("*");
				continue;
			}

			// !o
			int count = 0;
			for (int k = 0; k < 8; k++)
			{
				int new_i = i + *(*(pointer_to_each_condition_array + k));
				int new_j = j + *(*(pointer_to_each_condition_array + k) + 1);
				if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
					*(*(pointer_to_row_array + new_i) + new_j) == '*')
					count++;
			}

			//print element.
			printf("%c", (char)count + '0');
		}

		// print '\n'.
		printf("\n");
	}



	//free of array.
	for (int i = 0; i < n; i++)
	{
		free(*(pointer_to_row_array + i));
	}
	free(pointer_to_row_array);

	for (int i = 0; i < 8; i++)
	{
		free(*(pointer_to_each_condition_array + i));
	}
	free(pointer_to_each_condition_array);
	return 0;
}