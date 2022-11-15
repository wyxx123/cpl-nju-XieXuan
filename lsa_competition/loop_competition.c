//
// Created by xiexu on 2022/10/29.
//

/*
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//#define BIGGEST 1
//#define SMALLEST -1

bool IsLoopCompetition(const int* array);
int JudgePrivilege(const int* array1, const int* array2);
//int FindBest(const int* arr, bool (* type)(int, int));
int Sgn(int num);
//bool IsNotMax(int pro_best, int coming_num);
//bool IsNotMin(int pro_best, int coming_num);

int main(void)
{
	int times = 0;
	scanf("%d", &times);

	//one_back_crime 0-3 a,   4-7  b.
	int input[10][8] = { 0 };
	for (int i = 0; i < times; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}

	for (int i = 0; i < times; i++)
	{
		if (IsLoopCompetition(*(input + i)))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}

bool IsLoopCompetition(const int* array)
{
	int judges = JudgePrivilege(array, array + 4);

	const int* bigger_arr = NULL;
	const int* smaller_arr = NULL;
	if (judges == 0)
		return false;
	else if (judges > 0)
	{
		bigger_arr = array;
		smaller_arr = array + 4;
	}
	else
	{
		bigger_arr = array + 4;
		smaller_arr = array;
	}

//	int max = FindBest(bigger_arr, IsNotMax);
//	int min = FindBest(smaller_arr, IsNotMin);

	int array_c[4] = { 0 };
	for (int i1 = 1; i1 <= 10; i1++)
		for (int i2 = 1; i2 <= 10; i2++)
			for (int i3 = 1; i3 <= 10; i3++)
				for (int i4 = 1; i4 <= 10; i4++)
				{
					array_c[0] = i1;
					array_c[1] = i2;
					array_c[2] = i3;
					array_c[3] = i4;
					if ((JudgePrivilege(smaller_arr, array_c) == 1) && (JudgePrivilege(array_c, bigger_arr) == 1))
					{
						return true;
					}
				}
	return false;
}

int JudgePrivilege(const int* array1, const int* array2)
{
	int first_win_chance = 0;
	for (int i = 0; i < 4; i++)
	{
		int first_num = array1[i];
		for (int j = 0; j < 4; j++)
		{
			if (first_num != array2[j])
				first_win_chance += (first_num > array2[j]) ? 1 : -1;
		}
	}
	return Sgn(first_win_chance);
}

int Sgn(int num)
{
	return num / ((num == 0) ? 1 : abs(num));
}

//int FindBest(const int* arr, bool (* type)(int, int))
//{
//	int best = arr[0];
//	for (int i = 1; i <= 3; i++)
//	{
//		if ((*type)(best, arr[i]))
//			best = arr[i];
//	}
//	return best;
//}
//
//bool IsNotMax(int pro_best, int coming_num)
//{
//	if (pro_best < coming_num)
//		return true;
//	return false;
//}
//
//bool IsNotMin(int pro_best, int coming_num)
//{
//	if (pro_best > coming_num)
//		return true;
//	return false;
//}