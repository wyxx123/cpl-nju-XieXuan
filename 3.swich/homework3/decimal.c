//
// Created by xiexu on 2022/10/14.
//

//transfer: transfunc(input,transfer,len)
// if (0x30-0x39):-0x30
// else : -0x41
//
//check: every > len-1
//flag = 1;
//
//int answer =0;
//if
//for(i=0,<len)
//answer+=transfer[len-1-i]*pow(n,len-1-i)
//
//printf


#include <stdio.h>
#include <math.h>

void transfer_function(const char* input_arr, int* transfer_arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (input_arr[i] < 0x3A)
		{
			transfer_arr[i] = input_arr[i] - 0x30;
		}
		else
		{
			transfer_arr[i] = input_arr[i] - 0x41 + 10;
		}
	}
}

int main(void)
{
	int len = 0;
	int n = 0;
	char input_arr[31] = { 0 };
	int transfer_arr[31] = { 0 };

	scanf("%d%d\n", &len, &n);
	for (int i = 0; i < len; i++)
	{
		scanf("%c", input_arr + i);
	}

	transfer_function(input_arr, transfer_arr, len);

	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (transfer_arr[i] > n - 1)
		{
			flag = 1;
			break;
		}
	}

	int answer = 0;
	if (flag == 0)
	{
		for (int i = 0; i < len; i++)
		{
			int tem = len - i - 1;
			answer += transfer_arr[tem] * pow(n, i);
		}
	}

	if (flag == 1)
	{
		printf("Error");
	}
	else
	{
		printf("%d\n", answer);
	}

	;
	return 0;
}
