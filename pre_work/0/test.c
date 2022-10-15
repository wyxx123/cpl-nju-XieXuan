//
// Created by xiexu on 2022/9/23.
//
#include <stdio.h>
#include <assert.h>
void menu(void)
{
	printf("**************************************\n");
	printf("***     1.add         2.sub        ***\n");
	printf("***     3.mul         4.div        ***\n");
	printf("***            0.exit             ***\n");
	printf("**************************************\n");
}

int Add(int left_number, int right_number)
{
	return left_number + right_number;
}

int Sub(int left_number, int right_number)
{
	return left_number - right_number;
}

int Mul(int left_number, int right_number)
{
	return left_number * right_number;
}

int Div(int left_number, int right_number)
{
	return left_number / right_number;
}

int (*various_fuction[4]) (int, int) = { Add,Sub,Mul,Div };


int fuction(int input, int number_left, int number_right);

int main(void)
{
	int input = 0;
	int ret = 0;
	int number_left = 0;
	int number_right =0;
	do
	{
		menu();
		printf("please choose the function:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			printf("please put in number(left):>");
			scanf("%d", &number_left);
			printf("please put in number(right):>");
			scanf("%d", &number_right);
			ret = fuction(input,number_left,number_right);
			printf("the result is: %d\n", ret);
			break;
		default:
			printf("error,please log in again.\n");
			break;
		}
	} while (input);
	return 0;
}

int fuction(int input, int number_left, int number_right)
{
	assert((number_right != 0) || (input != 4));
	return various_fuction[input - 1](number_left, number_right);
}

