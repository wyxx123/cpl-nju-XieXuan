//
// Created by xiexu on 2022/12/4.
//
#include <stdio.h>

#define MAX_N 100000
#define MAX_GROUP 10000

int CountWriteGroup(int index_of_now, int group_sequence);

int is_in_group[MAX_N] = { 0 };
int input[MAX_N] = { 0 };
int ans_group_size[MAX_GROUP] = { 0 };

int main(void)
{
	int num_of_stu = 0;
	scanf("%d", &num_of_stu);

	char order[10] = { 0 };
	scanf("%10s", order);

	for (int i = 1; i <= num_of_stu; i++)
	{
		scanf("%d", input + i);
	}

	int count_of_group_num = 1;
	for (int i = 1; i <= num_of_stu; i++)
	{
		if (is_in_group[i] != 0)
			continue;

		int count_of_size = CountWriteGroup(i, count_of_group_num);
		ans_group_size[count_of_group_num] = count_of_size;
		count_of_group_num++;
	}

	count_of_group_num--;
	//sort
	for (int i = 1; i <= count_of_group_num - 1; i++)
	{
		for (int j = 1; j <= count_of_group_num - i; j++)
		{
			if (ans_group_size[j] < ans_group_size[j + 1])
			{
				int tmp = ans_group_size[j];
				ans_group_size[j] = ans_group_size[j + 1];
				ans_group_size[j + 1] = tmp;
			}
		}
	}


	//output
	if (order[0] == 'n')
		printf("%d\n", count_of_group_num);
	else
	{
		for (int i = 1; i <= count_of_group_num; i++)
		{
			printf("%d ", ans_group_size[i]);
		}
	}

	return 0;
}

int CountWriteGroup(int index_of_now, int group_sequence)
{
	if (is_in_group[index_of_now] != 0)
		return 0;

	is_in_group[index_of_now] = group_sequence;
	return CountWriteGroup(input[index_of_now], group_sequence) + 1;
}
