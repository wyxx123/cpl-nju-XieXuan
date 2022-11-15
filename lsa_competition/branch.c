//
// Created by xiexu on 2022/10/29.
//


#include <stdio.h>
#include <math.h>

char bucket_array[100000001] = { 0 };

int FindDifferentElement(int x, int y);
void BucketAssignmentForElement(int num, char* array);

int main(void)
{
	int x = 0;
	int y = 0;
	scanf("%d%d", &x, &y);

	int num = FindDifferentElement(x, y);
	printf("%d\n", (int)pow(2, num));
	return 0;
}

int FindDifferentElement(int x, int y)
{

	BucketAssignmentForElement(x, bucket_array);
	BucketAssignmentForElement(y, bucket_array);

	int count = 0;
	int times = (x > y) ? x : y;
	for (int i = 0; i <= times; i++)
	{
		if (bucket_array[i] != 0)
			count++;
	}

	return count;
}


void BucketAssignmentForElement(int num, char* array)
{
	while (num % 2 == 0)
	{
		array[2] = 1;
		num /= 2;
	}
	for (int i = 3; i <= num; i++)
	{
		while (num % i == 0)
		{
			array[i] = 1;
			num /= i;
		}
	}
}










//#include <stdio.h>
//#include <stdlib.h>
//
//void BucketAssignmentForElement(int num, int* count)
//{
//	while (num % 2 == 0)
//	{
//		(*count) *= 2;
//		num /= 2;
//	}
//	for (int i = 3; i <= num; i++)
//	{
//		while (num % i == 0)
//		{
//			(*count) *= i;
//			num /= i;
//		}
//	}
//}
//
//int main(void)
//{
//
//	int count = 1;
//	for (int i = 1; i < 1000000; i++)
//	{
//		BucketAssignmentForElement(i, &count);
//		if (count != i)
//		{
//			printf("failed at %d\n", i);
//			exit(9);
//		}
//		count = 1;
//	}
//	return 0;
//}

