//
// Created by xiexu on 2023/1/2.
//
#define MAX_WORD_PER_LINE 21
#define MAX_OUTPUT_LINE  50000
#define MAX_WORD_OUTPUT_PER_LINE 8

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char f_output[MAX_OUTPUT_LINE][MAX_WORD_OUTPUT_PER_LINE] = { 0 };
int f_output_index = 0;
char s_output[MAX_OUTPUT_LINE][MAX_WORD_OUTPUT_PER_LINE] = { 0 };
int s_output_index = 0;

int f_win = 0;
int f_lose = 0;
int s_win = 0;
int s_lose = 0;

void FirstPart(char input_char);
void SecondPart(char input_char);
bool FirstEnd(void);
bool SecondEnd(void);
void Print(void);

int main(void)
{
	char input[MAX_WORD_PER_LINE] = { 0 };
	while (scanf("%s", input) != EOF)
	{
		int index = 0;
		while (input[index] != 0)
		{
			if (input[index] == 'E')
			{
				sprintf(f_output[f_output_index++], "%d:%d", f_win, f_lose);
				sprintf(s_output[s_output_index++], "%d:%d", s_win, s_lose);
				break;
			}

			FirstPart(input[index]);
			SecondPart(input[index]);
			index++;
		}

#ifndef ONLINE_JUDGE
		if (input[index] == 'E')
			break;
#endif

		memset(input, 0, MAX_WORD_PER_LINE);
	}

	Print();

	return 0;
}

void FirstPart(char input_char)
{
	if (input_char == 'W')
		f_win++;
	else
		f_lose++;

	if (FirstEnd())
	{
		sprintf(f_output[f_output_index++], "%d:%d", f_win, f_lose);
		f_win = f_lose = 0;
	}
}

void SecondPart(char input_char)
{
	if (input_char == 'W')
		s_win++;
	else
		s_lose++;

	if (SecondEnd())
	{
		sprintf(s_output[s_output_index++], "%d:%d", s_win, s_lose);
		s_win = s_lose = 0;
	}
}

bool FirstEnd(void)
{
	return (f_win >= 11 && f_win - f_lose >= 2) || (f_lose >= 11 && f_lose - f_win >= 2);
}

bool SecondEnd(void)
{
	return (s_win >= 21 && s_win - s_lose >= 2) || (s_lose >= 21 && s_lose - s_win >= 2);
}

void Print(void)
{
	for (int i = 0; i < f_output_index; i++)
	{
		printf("%s\n", f_output[i]);
	}
	printf("\n");
	for (int i = 0; i < s_output_index; i++)
	{
		printf("%s\n", s_output[i]);
	}
}
