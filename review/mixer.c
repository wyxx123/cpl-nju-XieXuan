//
// Created by xiexu on 2023/2/18.
//
#include <stdio.h>

#define ARRAY_SIZE 8

int CharToNum(char input);
char NumToChar(int input);
int FindNum(char* array);
void PrintChar(int input);

int main(void)
{
	int input_size = 0;
	scanf("%d", &input_size);
	for (int i = 0; i < input_size; i++)
	{
		char array1[ARRAY_SIZE] = { 0 };
		char array2[ARRAY_SIZE] = { 0 };
		scanf("%s%s", array1, array2);

		//output
		printf("#");
		for (int j = 1; j < 7; j += 2)
		{
			PrintChar(FindNum(array1 + j) + FindNum(array2 + j));
		}
		printf("\n");
	}
	return 0;
}

int CharToNum(char input)
{
	if (input >= '0' && input <= '9')
		return input - '0';
	return input - 'A' + 10;
}

char NumToChar(int input)
{
	if (input >= 0 && input <= 9)
		return (char)(input + '0');
	return (char)('A' + input - 10);
}

int FindNum(char* array)
{
	return CharToNum(array[1]) + 16 * CharToNum(array[0]);
}

void PrintChar(int input)
{
	printf("%c%c", NumToChar(input / 16), NumToChar(input % 16));
}

