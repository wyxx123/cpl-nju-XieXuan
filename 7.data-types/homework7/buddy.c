//
// Created by xiexu on 2022/11/12.
//

/*
 * 16
 * 8,8
 * 4,4,8
 * 2,2,4,8
 * 1(1),1,2,4,8
 * 1(1),1,2,4,8(2)
 *
 *
 * 1(1),1,2,4(2),8,16,32,64
 *
 */

#include <stdio.h>
#include <math.h>

int size_of_each_buddy[20000] = { 0 };
int id_of_content[20000] = { 0 };

int function_A(int input_id, int input_size, int num_of_buddy);
void function_Q(int num_of_buddy);

int main(void)
{
	int n = 0;
	int num_of_operation = 0;

	scanf("%d%d", &n, &num_of_operation);
	int size_of_aggregated_buddy = (int)pow(2, n);
	size_of_each_buddy[0] = size_of_aggregated_buddy;

	int num_of_buddy = 1;
	for (int i = 0; i < num_of_operation; i++)
	{
		char temple_input = 0;
		scanf(" %c", &temple_input);
		if (temple_input == 'Q')
			function_Q(num_of_buddy);
		else
		{
			int input_id = 0;
			int input_size = 0;
			scanf("%d%d", &input_id, &input_size);
			int tmp_size = 1;
			for (tmp_size = 1; tmp_size < input_size; tmp_size *= 2);
			input_size = tmp_size;
			num_of_buddy = function_A(input_id, input_size, num_of_buddy);
		}
	}

	return 0;
}

int function_A(int input_id, int input_size, int num_of_buddy)
{
	for (int i = 0; i < num_of_buddy; i++)
	{
		if ((size_of_each_buddy[i] == input_size) && (id_of_content[i] == 0))
		{
			id_of_content[i] = input_id;
			return num_of_buddy;
		}
	}

	int check_element_index = 0;
	do
	{
		if ((size_of_each_buddy[check_element_index] == input_size) && (id_of_content[check_element_index] == 0))
		{
			id_of_content[check_element_index] = input_id;
			return num_of_buddy;
		}

		for (int i = 0; i < num_of_buddy; i++)
		{
			if ((size_of_each_buddy[i] > input_size) && (id_of_content[i] == 0))
			{
				for (int j = num_of_buddy - 1; j >= i + 1; j--)
				{
					id_of_content[j + 1] = id_of_content[j];
					size_of_each_buddy[j + 1] = size_of_each_buddy[j];
				}
				id_of_content[i + 1] = 0;
				size_of_each_buddy[i + 1] = size_of_each_buddy[i] / 2;
				size_of_each_buddy[i] = size_of_each_buddy[i + 1];
				num_of_buddy++;
				check_element_index = i;
				break;
			}
		}
	} while (1);
}

void function_Q(int num_of_buddy)
{
	printf("%d\n", num_of_buddy);
	for (int i = 0; i < num_of_buddy; i++)
	{
		printf("%d ", id_of_content[i]);
	}
	printf("\n");
}


