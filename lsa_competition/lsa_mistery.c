//
// Created by xiexu on 2022/10/29.
//

/*
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>

void Print_modified_array(const char* array);

int main(void)
{
	int T = 0;
	char input[100][1001] = { 0 };

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%1001s", *(input + i));
	}

	for (int i = 0; i < T; i++)
	{
		Print_modified_array(*(input + i));
	}

	return 0;
}

void Print_modified_array(const char* array)
{
	int sizes = (int)strlen(array);
	//printf("%d\n", sizes);

	for (int i = sizes - 1; i >= 0; i--)
	{
		if (array[i] != '*')
			printf("%c", array[i]);
	}
	printf("\n");
}
