//
// Created by xiexu on 2022/10/21.
//

/*
 *
 * NUM = 9
 * int arr[NUM][NUM]
 * for for scanf
 *
 * int flag =0
 * int target[10000]//?//tong
 * for(1-9)
 *
 * for(1-9)
 * target[arr[i][j]]++
 *
 * for(1-9)
 * if(target[]=1)
 * ~=0
 * else
 * flag=1
 * break;
 *
 * //row
 * if(flag == 0)
 *~~~~
 * //group
 * if(flag == 0)
 * for(i = 0 ; i += 3 ; i < NUM)
 *
 * for(j = 0 ; <NUM %3)
 *
 * is_wrong |= judge_group(array);
 * if(is_wrong == ture)
 *  break;
 * }
 * if(is_wrong ~~~~)
 *
 *
 *
 * judge:
 * 1. lines
 * 2. row
 * 3. groups
 * // 4. 1-9
 *
 *
 *
0     3     6
8 1 2 7 5 3 6 4 9 0
9 4 3 6 8 2 1 7 5
6 7 5 4 9 1 2 8 3
1 5 4 2 3 7 8 9 6 3
3 6 9 8 4 5 7 2 1
2 8 7 1 6 9 5 3 4
5 2 1 9 7 4 3 6 8 6
4 3 8 5 2 6 9 1 7
7 9 6 3 1 8 4 5 2
 *
 */



#define NUM 9

#include <stdio.h>
#include <stdbool.h>

bool judge_group(int input[NUM][NUM])
{
	//桶标记
	int target[10000] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			target[input[i][j]]++;
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		if (target[i] != 1)
		{
			return 1;
		}
	}

	return 0;
}

int main(void)
{
	int input[NUM][NUM] = { 0 };
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}

	bool is_wrong = false;
	int target[10000] = { 0 };
	//lines
	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < NUM; j++)
		{
			target[input[i][j]]++;
		}

		for (int j = 1; j <= NUM; j++)
		{
			if (target[j] == 1)
			{
				target[j] = 0;
			}
			else
			{
				is_wrong = true;
				break;
			}
		}

		if (is_wrong == true)
		{
			break;
		}
	}



	//row
	if (is_wrong == false)
	{
		for (int j = 0; j < NUM; j++)
		{
			for (int i = 0; i < NUM; i++)
			{
				target[input[i][j]]++;
			}

			for (int i = 1; i <= NUM; i++)
			{
				if (target[i] == 1)
				{
					target[i] = 0;
				}
				else
				{
					is_wrong = true;
					break;
				}
			}

			if (is_wrong == true)
			{
				break;
			}
		}
	}

	if (is_wrong == false)
	{
		for (int i = 0; i < NUM; i += 3)
		{
			for (int j = 0; j < NUM; j += 3)
			{
				is_wrong |= judge_group((int (*)[NUM])(&input[i][j]));//err: forgot to deliver the transferred position
				if (is_wrong == true)
				{
					break;
				}
			}
			if (is_wrong == true)
			{
				break;
			}
		}
	}

	if (is_wrong == false)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}