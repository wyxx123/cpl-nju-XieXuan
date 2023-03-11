//
// Created by xiexu on 2023/2/18.
//
//
// Created by xiexu on 2023/2/18.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 50000

int main(void)
{
	int height = 0;
	int width = 0;
	int op_time = 0;
	scanf("%d%d%d", &height, &width, &op_time);

	int** line_array = malloc((width + 1) * sizeof(int*));
	for (int i = 1; i <= width; i++)
	{
		line_array[i] = malloc(MAX_HEIGHT * sizeof(int));
	}
	int* size_array = malloc((width + 1) * sizeof(int));

	for (int i = 1; i <= width; i++)
	{
		size_array[i] = height;
	}

	for (int cur_h = height; cur_h >= 1; cur_h--)
	{
		for (int cur_w = 1; cur_w <= width; cur_w++)
		{
			scanf("%d", &(line_array[cur_w][cur_h]));
		}
	}

	for (int i = 0; i < op_time; i++)
	{
		int src = 0;
		int dest = 0;
		scanf("%d%d", &src, &dest);
		(size_array[dest])++;
		(line_array[dest])[size_array[dest]] = (line_array[src])[1];
		for (int i = 1; i < size_array[src]; i++)
		{
			(line_array[src])[i] = (line_array[src])[i + 1];
		}
//	line_array[src][size_array[src]] = -1;
		(size_array[src])--;
	}

	int max = 0;
	for (int i = 1; i <= width; i++)
	{
		max = (max >= size_array[i]) ? max : size_array[i];
	}

	for (int i = max; i >= 1; i--)
	{
		for (int j = 1; j <= width; j++)
		{
			if (i <= size_array[j])
				printf("%5d", (line_array[j])[i]);
			else
				printf("     ");
		}
		printf("\n");
	}
	free(size_array);
	for (int i = 1; i <= width; i++)
	{
		free(line_array[i]);
	}
	free(line_array);
	return 0;
}

//         4
//         5
//         2    3
//         3    4
//    1    2    3