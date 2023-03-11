//
// Created by xiexu on 2023/2/7.
//

//err

#include <stdio.h>
#include <string.h>

#define MAX_TIME_Q 100000

int array_size = 0;
int array[MAX_TIME_Q] = { 0 };

int main(void)
{

	int q_time = 0;
	scanf("%d%*d", &q_time);

	for (int i = 0; i < q_time; i++)
	{
		char command[15] = { 0 };
		int input_number = 0;
		scanf("%15s%d", command, &input_number);

		if (!strcmp(command, "Add"))
		{
			int cur_index = 0;
			while (cur_index < array_size && array[cur_index] > input_number)
				cur_index++;

			//move
			for (int j = array_size - 1; j >= cur_index; j--)
				array[j + 1] = array[j];

			//put
			array[cur_index] = input_number;

			array_size++;
		}
		else if (!strcmp(command, "Query"))
		{
			if (input_number > array_size)
				printf("No Answer\n");
			else
				printf("%d\n", array[input_number - 1]);
		}
		else
		{
			printf("%s\n", command);
		}
	}

	return 0;
}