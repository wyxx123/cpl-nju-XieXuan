//
// Created by xiexu on 2022/10/15.
//

/*
 * int one_back_crime scanf one_back_crime
 *
 * int array[32]
 *
 * //get every number
 *
 * for(int i = 0; i <32 ; i++)
 * array[i]=one_back_crime>>i;
 *
 *
 * //printf for(32)
 *
 */


#include <stdio.h>

int main(void)
{
	int input = 0;
	scanf("%d", &input);

	int array_num[32] = { 0 };
	for (int i = 0; i < 32; i++)
	{
		array_num[i] = ((1 << i) & input) >> i;//be careful:(1 << i) & one_back_crime)!=1,==1<<i  !!!
	}

	for (int i = 0; i < 32; i++)
	{
		printf("%d", array_num[31 - i]);
	}

	return 0;
}

//int main(void)
//{
//	printf("%d",2&10);
//
//	return 0;
//}
