//
// Created by xiexu on 2022/11/1.
//
#include <stdio.h>



int test__(void);

int main(void)
{
	int test = 0;
	(void)printf("%d", 1);

	(void)test__();
	return 0;
}


/**
 *
 * @return number1-random number
 */
int test__(void)
{
	printf("test\n");
	return 1;
}
