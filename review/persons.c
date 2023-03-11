//
// Created by xiexu on 2023/2/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool FiveSuit(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5);
bool CanGroup(int* array1, int* array2, int* array3);

int num_of_person = 0;
int num_of_trail = 0;
int main(void)
{

	scanf("%d%d", &num_of_person, &num_of_trail);

	int** persons_array = malloc(num_of_person * sizeof(*persons_array));
	for (int i = 0; i < num_of_person; i++)
	{
		persons_array[i] = malloc(num_of_trail * sizeof(int));
		for (int j = 0; j < num_of_trail; j++)
		{
			scanf("%d", &persons_array[i][j]);
		}
	}

	int output = 0;
	for (int i = 0; i < num_of_person; i++)
		for (int j = i + 1; j < num_of_person; j++)
			for (int k = j + 1; k < num_of_person; k++)
				for (int l = k + 1; l < num_of_person; l++)
					for (int m = l + 1; m < num_of_person; m++)
						if (FiveSuit(persons_array[i], persons_array[j], persons_array[k], persons_array[l],
								persons_array[m]))
							output++;

	printf("%d\n", output);
	for (int i = 0; i < num_of_person; i++)
	{
		free(persons_array[i]);
	}
	free(persons_array);
	return 0;
}

bool FiveSuit(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5)
{
	int count = 0;
	int* store_array[5] = { arr1, arr2, arr3, arr4, arr5 };
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			for (int k = j + 1; k < 5; k++)
				if (CanGroup(store_array[i], store_array[j], store_array[k]))
					count++;
	if (count >= 2)
		return true;
	return false;
}
bool CanGroup(int* array1, int* array2, int* array3)
{
	for (int i = 0; i < num_of_trail; i++)
		if ((array1[i] != array2[i] || array2[i] != array3[i])
				&& ((array1[i] == array2[i]) || (array1[i] == array3[i]) || (array3[i] == array2[i])))
			return false;
	return true;
}

