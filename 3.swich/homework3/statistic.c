//
// Created by xiexu on 2022/10/14.
//

#include <stdio.h>


//count[127]
//scanf input
//scanf  - input times
//count[c]++
//
//计数下最多的，及多少个格
//
//{（count+count ！= 0）
//a a+32 有（最多-i < 次数）-打印= 没有 （不为0）' '
//打印' '
//}
//打印--（多少格）
//
//打印字母

void printf_equ(int condition)
{
	if (condition == 1)
	{
		printf("=");
	}
	else if (condition == 0)
	{
		printf(" ");
	}
}

int compare_equ(int* array, int sequence, int cmp)  //cmp = max_times - i
{
	if (array[sequence] >= cmp)
	{
		return 1;
	}
	else if (array[sequence] != 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int get_max_26(const int* arr)
{
	int max = arr[0];
	for (int i = 1; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}

int main(void)
{
	int count[127] = { 0 };
	int input = 0;
	char tmp_input = 0;

	scanf("%d\n", &input);
	for (int i = 0; i < input; i++)
	{
		scanf("%c", &tmp_input);
		count[(int)tmp_input]++;
	}

	int max_times = 0;
	int width = 0;
	for (int i = 0; i < 26; i++)
	{
		if ((count[i + 0x41] != 0) && (count[i + 0x61] != 0))
		{
			width += 3;
		}
		else if ((count[i + 0x41] != 0) || (count[i + 0x61] != 0))
		{
			width += 2;
		}
	}
	width--;

	max_times = get_max_26(count + 0x41);
	int _max = get_max_26(count + 0x61);
	if (_max > max_times)
	{
		max_times = _max;
	}

	for (int i = 0; i < max_times; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			int h_ret = compare_equ(count, j + 0x41, max_times - i);
			int s_ret = compare_equ(count, j + 0x61, max_times - i);

			if ((h_ret != -1) || (s_ret != -1))
			{
				printf_equ(s_ret);
				printf_equ(h_ret);
				printf(" ");
			}
		}

		printf("\n");
	}

	for (int i = 0; i < width; i++)
	{
		printf("-");
	}
	printf("\n");

	for (int i = 0; i < 26; i++)
	{
		int h_ret = compare_equ(count, i + 0x41, 1);
		int s_ret = compare_equ(count, i + 0x61, 1);

		if ((h_ret != -1) || (s_ret != -1))
		{
			if (s_ret == 1)
			{
				printf("%c", i + 0x61);
			}
			if (h_ret == 1)
			{
				printf("%c", i + 0x41);
			}
			printf(" ");
		}
	}

	return 0;
}