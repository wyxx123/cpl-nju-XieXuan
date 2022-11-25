//
// Created by xiexu on 2022/11/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	char* S = malloc(100005);
	char* T = malloc(100005);
	scanf("%100005s%100005s", S, T);
	assert(T != NULL && S != NULL);

	int len_S = (int)strlen(S);
	int len_T = (int)strlen(T);
	char* T_size_S = malloc(len_T + 1);
	assert(T_size_S != NULL);

	*(T_size_S + len_T) = 0;

	for (int i = 0; i < len_S - len_T + 1; i++)
	{
		strncpy(T_size_S, S + i, len_T);

		if (!(strcmp(T_size_S, T)))
		{
			printf("%d ", i);
		}

	}

	free(T_size_S);
	free(S);
	free(T);
	return 0;
}