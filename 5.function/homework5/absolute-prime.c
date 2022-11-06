//
// Created by xiexu on 2022/10/28.
//

/*
 * scanf n
 *
 * int count = 0;
 *
 * bool IsAbsolutePrime(int num)
 *  if(!IsPrime(num)) return false;
 *  int sub_num = swap_int(num);
 *  IsPrime```
 *
 * bool IsPrime(int num)
 * int x; // 要判定是否是素数的数
int flag = 1; // 1 表示该数是素数
for (int i = 2; i <= sqrt(x + 0.5); i++) {
    if (x % i == 0) {
        flag = 0;
    }
}
 *
 * int swap_int(int num)
 * int bit_int[4]
 * int times = 0;
 * int return_value =0;
 * while(num/10)
 * bit_int[times++] = num%10;
 * num /= 10;
 *
 *
 * while(bit_int[times]&&times>=0)
 * ret += bit_int[times--];
 * ret *= 10;
 *
 *
 * for(int i = 1 <=n )
 * if(Is`Prime(i))
 * count++
 *
 * printf("%d\n",count)
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool IsAbsolutePrime(int num);
bool IsPrime(int x);
int SwapInt(int num);

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		if (IsAbsolutePrime(i))
		{
			//printf("%d ", i);
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}

bool IsAbsolutePrime(int num)
{
	if (!IsPrime(num))
		return false;
	int sub_num = SwapInt(num);
	if (!IsPrime(sub_num))
		return false;
	return true;
}

bool IsPrime(int x)//要判定是否是素数的数
{
	for (int i = 2; i <= sqrt(x + 0.5); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

int SwapInt(int num)
{
	int bit_int[4] = { 0 };
	int times = 0;
	int count = 1;
	int return_value = 0;

	while (num / 10)
	{
		bit_int[times++] = num % 10;
		num /= 10;
		count++;
	}
	bit_int[times] = num;
	times = 0;

	while (times < count)
	{
		return_value *= 10;
		return_value += bit_int[times++];
	}
	return return_value;
}


