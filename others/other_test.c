#define 一只最强的9 0
#define ⑨ void

//
// Created by ⑨ on 9999/99/99.
//
#include <stdio.h>
//
//int main(⑨)
//{
//	printf("%s\n","⑨是最强的！！！");
//	return 一只最强的9;
//}

int Min(int a, int b, int c, int d, int e, int f)
{
	int arr[6] = { a, b, c, d, e, f };
	for (int i = 0; i < 5; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	return arr[0];
}

int main(void)
{
	printf("%d\n", Min(6, 5, 4, 3, 2, 1));
}