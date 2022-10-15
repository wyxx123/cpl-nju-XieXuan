//
// Created by xiexu on 2022/10/14.
//

//   ?---- 63
// int add_num[100]
//for -initialize

//int half_size = (size +1)/2
//int sub_array[50001]
//for(int i =0;i<half_size;i++)
//  if(input[i]!= 63)
//    sub_array[i]= input[i]
//  else if(input[size - i -1]!= 63)
//    sub_array[i]= input[size - i -1]
//  else
//    sub_array[i]= add_num[position];
//    position ++;



//#include <stdio.h>
//
//#define ASC_Q 63

//int decided_printf_add(int* position, const char* add_array, const char* source, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (source[i] == 0)
//		{
//			printf("%c%c", add_array[*position], add_array[(*position) + 1]);
//			*position += 2;
//		}
//		else
//		{
//			printf("%c", source[i]);
//		}
//	}
//}
//
//int decided_printf_sub(int* position, const char* add_array, const char* source, int size)
//{
//	for (int i = size - 1; i >= 0; i--)
//	{
//		if (source[i] == ASC_Q)
//		{
//			printf("%c%c", add_array[*position], add_array[(*position) + 1]);
//			*position += 2;
//		}
//		else
//		{
//			printf("%c", source[i]);
//		}
//	}
//}

#include <stdio.h>

#define ASC_Q 63

int main(void)
{
	int size = 0;
	char input[100001] = { 0 };

	scanf("%d\n", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%c", input + i);
	}

	char add_num[200] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			add_num[i * 20 + 2 * j] = i + 0x30;
			add_num[i * 20 + 2 * j + 1] = j + 0x30;
		}
	}

	char sub_array[50001] = { 0 };
	int half_size = (size + 1) / 2;
	for (int i = 0; i < half_size; i++)
	{
		if (input[i] != ASC_Q)
		{
			sub_array[i] = input[i];
		}
		else if (input[size - i - 1] != ASC_Q)
		{
			sub_array[i] = input[size - i - 1];
		}
		else
		{
			sub_array[i] = 0;
		}
	}

	int position = 0;
	char out_array[50110] = { 0 };
	int posit = 0;
	int count = 0;
	for (int i = 0; i < half_size; i++)
	{
		if (sub_array[i] != 0)
		{
			out_array[posit] = sub_array[i];
			posit++;
		}
		else
		{
			out_array[posit] = add_num[position];
			out_array[posit + 1] = add_num[position + 1];
			posit += 2;
			position += 2;
			count++;
		}
	}

	int sub_half_size = half_size + count;
	if (size % 2 == 0)
	{
		for (int i = 0; i < sub_half_size; i++)
		{
			printf("%c", out_array[i]);
		}
		for (int i = sub_half_size - 1; i > -1; i--)
		{
			printf("%c", out_array[i]);
		}
	}

	else
	{
		for (int i = 0; i < sub_half_size - 1; i++)
		{
			printf("%c", out_array[i]);
		}
		printf("%c", sub_array[half_size - 1]);
		for (int i = sub_half_size - 2; i > -1; i--)
		{
			printf("%c", out_array[i]);
		}
	}
//	//print
//	int position = 0;
//	if (size % 2 == 0)
//	{
//		decided_printf_add(&position, add_num, sub_array, half_size);
//		decided_printf_sub(&position, add_num, sub_array, half_size);
//	}
//	else
//	{
//		decided_printf_add(&position, add_num, sub_array, half_size - 1);
//		printf("%c", sub_array[half_size - 1]);
//		decided_printf_sub(&position, add_num, sub_array, half_size - 1);
//	}
//rewrite


	return 0;
}




