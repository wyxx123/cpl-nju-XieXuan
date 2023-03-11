////
//// Created by xiexu on 2022/12/4.
////
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAX_N  75
//#define MAX_K  10
//
//int ans[MAX_N * MAX_N * MAX_N][3] = { 0 };
//int judge_array[MAX_N][MAX_K] = { 0 };
//int tmp_count = 0;
//
//int n = 0;
//
//int JudgeCanTeam(int row);
//
//int main(void)
//{
//	int k = 0;
//	scanf("%d%d", &n, &k);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 1; j <= k; j++)
//		{
//			scanf("%d", &judge_array[i][j]);
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			for (int l = j + 1; l < n; l++)
//			{
//				ans[tmp_count][0] = i;
//				ans[tmp_count][1] = j;
//				ans[tmp_count][2] = l;
//				tmp_count++;
//			}
//		}
//	}
//
//	int count = JudgeCanTeam(k);
//
//	int(* five_ans)[5] = malloc(count * count * 5 * sizeof(int));
//
//	int ans_count = 0;
//	for (int i = 0; i < tmp_count; i++)
//	{
//		if (ans[i][0] == -1)
//			continue;
//
//		for (int j = i + 1; j < tmp_count; j++)
//		{
//			if (ans[j][0] == -1)
//				continue;
//
//
//			int count_of_diff = 0;
//			for (int l = 0; l < 3; l++)
//			{
//				if (ans[j][l] != ans[i][0]
//					&& ans[j][l] != ans[i][1]
//					&& ans[j][l] != ans[i][2])
//					count_of_diff++;
//			}
//			if (count_of_diff == 2)
//			{
//				ans_count++;
//			}
//		}
//	}
//
//	printf("%d", ans_count);
//	free(five_ans);
//	return 0;
//}
//
//// -1 : not team
//int JudgeCanTeam(int row)
//{
//	if (row == 0)
//		return n * n * n;
//
//	int pre_term_count = JudgeCanTeam(row - 1);
//
//	for (int i = 0; i < tmp_count; i++)
//	{
//		if (ans[i][0] == -1)
//			continue;
//
//		if (judge_array[ans[i][0]][row] == judge_array[ans[i][1]][row]
//			&& judge_array[ans[i][1]][row] == judge_array[ans[i][2]][row])
//			continue;
//
//		if (judge_array[ans[i][0]][row] != judge_array[ans[i][1]][row]
//			&& judge_array[ans[i][1]][row] != judge_array[ans[i][2]][row])
//			continue;
//
//		ans[i][0] = -1;
//		pre_term_count--;
//	}
//
//	return pre_term_count;
//}


//
// Created by xiexu on 2022/12/4.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N  75
#define MAX_K  10

int ans[5 * 5 * 5][3] = { 0 };
int judge_array[5][MAX_K] = { 0 };
int input_array[MAX_N][MAX_K] = { 0 };
int tmp_count = 0;

int n = 0;
int k = 0;

int JudgeCanTeam(int row);
void IntArrayCopy(int* dest, int* from, int size);
bool Function(void);

int main(void)
{
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			scanf("%d", &input_array[i][j]);
		}
	}

	int ans_count = 0;
	for (int i = 0; i < n; i++)
	{
		IntArrayCopy(judge_array[0], input_array[i], k);
		for (int j = i + 1; j < n; j++)
		{
			IntArrayCopy(judge_array[1], input_array[j], k);
			for (int l = j + 1; l < n; l++)
			{
				IntArrayCopy(judge_array[2], input_array[l], k);
				for (int m = l + 1; m < n; m++)
				{
					IntArrayCopy(judge_array[3], input_array[m], k);
					for (int i1 = m + 1; i1 < n; i1++)
					{
						IntArrayCopy(judge_array[4], input_array[i1], k);
						if (Function())
							ans_count++;
					}
				}
			}
		}
	}

	printf("%d", ans_count);

	return 0;
}

bool Function(void)
{
	tmp_count = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int l = j + 1; l < 5; l++)
			{
				ans[tmp_count][0] = i;
				ans[tmp_count][1] = j;
				ans[tmp_count][2] = l;
				tmp_count++;
			}
		}
	}

	int count = JudgeCanTeam(k);
	if (count >= 2)
		return true;
	return false;
}

// -1 : not team
int JudgeCanTeam(int row)
{
	if (row == 0)
		return 10;

	int pre_term_count = JudgeCanTeam(row - 1);

	for (int i = 0; i < tmp_count; i++)
	{
		if (ans[i][0] == -1)
			continue;

		if (judge_array[ans[i][0]][row] == judge_array[ans[i][1]][row]
			&& judge_array[ans[i][1]][row] == judge_array[ans[i][2]][row])
			continue;

		if (judge_array[ans[i][0]][row] != judge_array[ans[i][1]][row]
			&& judge_array[ans[i][1]][row] != judge_array[ans[i][2]][row]
			&& judge_array[ans[i][0]][row] != judge_array[ans[i][2]][row])
			continue;

		ans[i][0] = -1;
		pre_term_count--;
	}

	return pre_term_count;
}

void IntArrayCopy(int* dest, int* from, int size)
{
	for (int i = 0; i <= size; i++)
	{
		dest[i] = from[i];
	}
}


