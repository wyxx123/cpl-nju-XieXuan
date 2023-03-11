//
// Created by xiexu on 2023/1/6.
//
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 110

int FindInt(char input);
void Print(int index);

int main(void)
{
	char input[MAX_INPUT] = { 0 };
	int array[15] = { 0 };
	scanf("%s", input);
	int size = strlen(input);
	for (int i = 0; i < size; i++)
	{
		if (input[i] == '1' && input[i + 1] == '0')
		{
			array[7]++; //10
			i++;
		}
		else
			array[FindInt(input[i])]++;
	}

	int count = 0;
	int cur = 0;
	int cur_count = 0;
	int index = -1;
	for (int i = 0; i < 11; i++)
	{
		if (array[i] >= 2)
		{
			cur = i;
			while (array[cur] >= 2)
			{
				cur_count++;
				cur++;
			}
			if (cur_count > count)
			{
				count = cur_count;
				index = i;
			}
			i = cur;
			cur_count = 0;
		}
	}

	for (int i = index; i < index + count; i++)
	{
		Print(i);
		Print(i);
	}
	printf("\n");

	return 0;
}

int FindInt(char input)
{
	if (input >= '3' && input <= '9')
		return input - '3';
	if (input == 'J')
		return 8;
	if (input == 'Q')
		return 9;
	if (input == 'K')
		return 10;

	return 11;
}

void Print(int index)
{
	if (index >= 0 && index <= 6)
		printf("%c", index + '3');
	else if (index == 7)
		printf("10");
	else if (index == 8)
		printf("J");
	else if (index == 9)
		printf("Q");
	else if (index == 10)
		printf("K");
	else
		printf("A");
}

