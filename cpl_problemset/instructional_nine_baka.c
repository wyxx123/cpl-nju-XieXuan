//
// Created by xiexu on 2022/11/5.
//



#include <stdio.h>

char input[1000000] = { 0 };

int main(void)
{
	int count = -1;
	while (scanf(" %c", &input[++count]) != EOF);

	int result = 0;
	for (int i = 0; i < count; i++)
	{
		result += input[i] - '0';
		result %= 9;
	}
	printf("%d\n", result);

	return 0;
}

//this morning, I award myself with this problem.(doge)
//            --by wy_xx123    20222205
