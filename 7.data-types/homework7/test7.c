//
// Created by xiexu on 2022/11/12.
//
//#include <stdio.h>
//#include <time.h>
//#include <float.h>
//#include <stdbool.h>
//#include <math.h>
//
//int main(void)
//{
//	clock_t start = clock();
//	for (int i = 0; i < 1000; i++)
//	{
//		printf("%d", 9);
//	}
//	clock_t end = clock();
//
//	printf("time is %ld\n", end - start);
//	printf("clocks_per_sec is %d\n", CLOCKS_PER_SEC);
//
//	float f1 = 1.00000001f;
//	float f2 = 1.00000002f;
//
//	bool judge = (f1 == f2);
//	printf("%d\n", judge);
//
//	bool pro_judge = (fabs(f1 - f2) <= DBL_EPSILON);
//	printf("%d\n", pro_judge);
//
//	return 0;
//}

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool IsEqual(double x, double y);

int main()
{
	printf("%d\n", IsEqual(DBL_MAX, DBL_MAX - 100));

	printf("%.50f\n", DBL_MAX - (DBL_MAX - 100));

	return 0;
}

bool IsEqual(double x, double y)
{
	return fabs(x - y) <= DBL_EPSILON; //能容忍的最小误差。。。:
}