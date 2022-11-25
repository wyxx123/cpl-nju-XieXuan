//
// Created by xiexu on 2022/11/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	char* word = malloc(5000 * sizeof(char));
	assert(word != 0);
	char char_judge_if_end = 0;

	do
	{
		memset(word, 0, 5000 * sizeof(char));
		scanf("%5000s", word);
		int string_len = (int)strlen(word);

		for (int i = 0; i < string_len; i++)
		{
			if (i == 0)
			{
				char bias = ((*word >= 'a') && (*word <= 'z')) ? ('A' - 'a') : 0;  //bias: to change to BIG
				printf("%c", *word + bias);
			}

			else
			{
				char bias = ((*(word + i) >= 'A') && (*(word + i) <= 'Z')) ? ('a' - 'A') : 0;
				//bias: to change to small
				printf("%c", *(word + i) + bias);
			}
		}
		printf(" ");

		scanf("%c", &char_judge_if_end);
	} while (char_judge_if_end != '\n');

	free(word);
	return 0;
}

//舍命玩·搞个大新·文