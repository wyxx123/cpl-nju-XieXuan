//
// Created by xiexu on 2022/11/1.
//
//#include <stdio.h>
//
//
//
//int test__(void);
//
//int main(void)
//{
//	int test = 0;
//	(void)printf("%d", 1);
//
//	(void)test__();
//	return 0;
//}
//
//
///**
// *
// * @return number1-random number
// */
//int test__(void)
//{
//	printf("test\n");
//	return 1;
//}


#include <stdio.h>

int main(void)
{
	int n = 3;
	int ans[3][3] = {{ 1, 2, 3 },
					 { 4, 5, 6 },
					 { 7, 8, 9 }};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", ans[i][j], " \n"[j + 1 == n]);
	// 这是一种新奇的输出空格or换行的方式，大家自行领悟
	return 0;
}