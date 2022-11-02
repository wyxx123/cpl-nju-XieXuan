//
// Created by xiexu on 2022/10/29.
//



//#include <stdio.h>
//#include <math.h>
//
//int LSAXiaoGongZhu(int a, int b, int k)
//{
// //	int ret = 0;
// //	if ((k * b % a) != 0)
// //		ret -= 1;
//
//	return b + (((k * b % a) != 0) ? -1 : 0);
//}

//int main(void)
//{
//	int times = 0;
//	scanf("%d", &times);
//
//	int input[100000][2] = { 0 };
//	for (int i = 0; i < times; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			scanf("%d", &input[i][j]);
//		}
//	}
//
//	for (int i = 0; i < times; i++)
//	{
//		int result = 0;
//		if (input[i][0] % 2 == 0)
//			result += (int)floor(input[i][1] / 2.0);
//
//		for (int j = 1; j <= (input[i][0] - 1) / 2; j++)
//		{
//			//result += LSAXiaoGongZhu(input[i][0], input[i][1], j);
//			result +=  input[i][1] + (((j * input[i][1] % input[i][0]) != 0) ? -1 : 0);
//		}
//
//
//		printf("%d\n", result);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int times = 0;
//	scanf("%d", &times);
//
//	int input[100000][2] = { 0 };
//	for (int i = 0; i < times; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			scanf("%d", &input[i][j]);
//		}
//	}
//
//	for (int i = 0; i < times; i++)
//	{
//		int result = 0;
//
//		for (int j = 1; j < input[i][0]; j++)
//		{
//			result += j * input[i][1] / input[i][0];
//		}
//		printf("%d\n", result);
//	}
//
//	return 0;
//}

#include <stdio.h>

int main(void)
{
	int times = 0;
	scanf("%d", &times);

	int input[100000][2] = { 0 };
	for (int i = 0; i < times; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}

	for (int i = 0; i < times; i++)
	{
		int result = 0;

		for (int j = 1; j < input[i][0]; j++)
		{
			result += j * input[i][1] / input[i][0];
		}
		printf("%d\n", result);
	}

	return 0;
}

