//
// Created by xiexu on 2022/10/9.
//
//桶标记法：一个数组，序号本身为“桶”，对应的内容用于计数
//previous:
//#include <stdio.h>
//
//int main(void)
//{
//	int one_back_crime[200000] = { 0 };
//	int n = 0;
//	int flag[1000000] = { 0 };
//
//	scanf("%d", &n);
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		scanf("%d", one_back_crime + i);
//	}
//
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		flag[one_back_crime[i]]++;
//	}
//
//	for (int i = 1; i < 1000000; i++)
//	{
//		if (flag[i] == 1)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}


//
//int* /*name*/ = 0;
//for(int i = 0; i < /*sizes*/ ; i++)
//{
//	/*name*/[i] = 0;
//}
//

//
//#include <stdio.h>
//
//int main(void)
//{
//	int n = 0;
//
//	int _flag = 0;
//	int* flag = &_flag;
//	for (int i = 0; i < 1000; i++)
//	{
//		flag[i] = 0;
//	}
//
//	int _input = 0;
//	int* one_back_crime = &_input;
//	for (int i = 0; i < 200; i++)
//	{
//		one_back_crime[i] = 0;
//	}
//
//	scanf("%d", &n);
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		scanf("%d", one_back_crime + i);
//	}
//
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		flag[one_back_crime[i]]++;
//	}
//
//	for (int i = 1; i < 1000000; i++)
//	{
//		if (flag[i] == 1)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}


//try to use 递归
//scanf
//int n = fun()  //next
#include <stdio.h>

//int main(void)
//{
//
//	return 0;
//}
//err

//我们这里先讲两个前导知识：
//0 ^ x = x，x 异或 0 的结果还是 x
//x ^ x = 0，两个相同的数异或结果为 0
//根据这两个性质，我们可以在 2 * n + 1 个数中，轻易的找出落单的一个数。eg： 1 ^ 1 ^ 2 ^ 2 ^ 3 = 3

#include <stdio.h>

int main(void)
{
	int all = 0;
	int times = 0;
	scanf("%d", &times);
	for (int i = 0; i < 2 * times - 1; i++)
	{
		int input = 0;
		scanf("%d", &input);
		all = all ^ input;
	}
	printf("%d\n", all);
	return 0;
}

//位运算的奇妙用途 QAQ
//顺便一提，遍历是不用数组的特性，故常转换成 连加/连×（连异或（大雾））的数学运算结果