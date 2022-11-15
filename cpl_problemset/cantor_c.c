//
// Created by xiexu on 2022/11/1.
//


#include <stdio.h>

int main(void)
{
	int input = 0;
	scanf("%d", &input);

	int high_loop = 0;
	int high_range = 0;
	for (high_loop = 1;; high_loop++)
	{
		high_range = high_loop * (high_loop + 1) / 2;
		if (input <= high_range)
		{
			break;
		}
	}

	int bias = high_range - input;
	if (high_loop % 2 == 0)
		printf("%d/%d", high_loop - bias, 1 + bias);
	else
		printf("%d/%d", 1 + bias, high_loop - bias);

	return 0;
}


//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 1; n - i > 0; i++)
//	{
//		n -= i;//减输入
//	}
//	if (i % 2 == 0)
//		printf("%d/%d", n, i + 1 - n);
//	else
//		printf("%d/%d", i + 1 - n, n);
//	return 0;
//}

//err: didn't understand the problem...

//add:  the process of calculation has been repeated