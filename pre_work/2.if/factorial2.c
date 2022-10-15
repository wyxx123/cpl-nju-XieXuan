//
// Created by xiexu on 2022/10/10.
//

//previous
//#include <stdio.h>
//
//#define _mod 1000000007
//
//int main(void)
//{
//	int input = 0;
//	int half_result = 1;
//	int result = 0;
//
//	scanf("%d", &input);
//
//	for (int i = 1; i <= input; i++)
//	{
//		half_result *= i % _mod;
//		half_result %= _mod;
//		result += half_result % _mod;
//	}
//
//	printf("%d\n", result % _mod);
//
//	return 0;
//}



//int tem = max_int/num; times
//times<=tem -- *
//times>tem  -- -max_int*(times/tem)


#include <stdio.h>
//1000000007
//10007
#define _mod 1000000007
#define max_int 2147483647

//int mul_mod(int num, int times)
//{
//	int result = 0;
//	for (int i = 0; i < times; i++)
//	{
//		int tmp = num - max_int + result;
//		if (tmp > 0)
//		{
//			result -= _mod;
//		}
//		result += num;
//	}
//	return result;
//}

int mul_mod(int num, int times)
{
	int tmp = max_int / num;
	if (tmp >= times)
	{
		return num * times;
	}
	else
	{
		int testing = _mod * (times / tmp);
		int answer = num * times - _mod * (times / tmp);
		return answer;
	}

}

int main(void)
{
	int input = 0;
	int half_result = 1;
	int result = 0;

	scanf("%d", &input);

	for (int i = 1; i <= input; i++)
	{
		half_result = mul_mod(half_result, i);
		half_result %= _mod;

		if (result + half_result < 0)
		{
			result -= _mod;
		}
		result += half_result;
		result %= _mod;
	}

	printf("%d\n", result % _mod);

	return 0;
}//err???

//time over 1200
//QAQ   O（n^2）









//test  sizeof(int)

//#include <stdio.h>
//
//int main(void)
//{
//	printf("%d\n",sizeof(int));
//	return 0;
//}

//test max_int

//#include <stdio.h>
//
//#define max_int 2147483647
//
//int main(void)
//{
//	int a = max_int / 2;
//	int b = max_int / 2 + 100;
//	int i = a + b;
//	int num = i - max_int;
//	if ((i - max_int) > 0)  //two varieties smaller than 0 , not calculation(?)
//	{
//		printf("222\n");
//	}
//	if (num > 0)
//	{
//		printf("333\n");
//	}
//	return 0;
//}
