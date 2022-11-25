//
// Created by xiexu on 2022/11/18.
//
//#include <stdio.h>
//#include <math.h>
//
//int main(void)
//{
//	unsigned int num = 0;
//	for (int i = 7; i >= 0; i--)
//	{
//		char tmp_input = 0;
//		unsigned int int_input = 0;
//		scanf("%c", &tmp_input);
//		if (tmp_input >= '0' && tmp_input <= '9')
//			int_input = tmp_input - '0';
//		else
//			int_input = tmp_input - 'a' + 10;
//		num += int_input * (int)pow(16, i);
//	}
//
//	const float* fl = (float*)&num;
//	printf("%d\n%u\n%.6f\n%.4g\n", num, num, *fl, *fl);
//
//	return 0;
//}

//267234249



//
// Created by xiexu on 2022/11/18.
//
//#include <stdio.h>
//#include <math.h>
//
//int main(void)
//{
//	int num = 0;
//	for (int i = 7; i >= 0; i--)
//	{
//		char tmp_input = 0;
//		int int_input = 0;
//		scanf("%c", &tmp_input);
//		if (tmp_input >= '0' && tmp_input <= '9')
//			int_input = tmp_input - '0';
//		else
//			int_input = tmp_input - 'a' + 10;
//		num += int_input * (int)pow(16, i);
//	}
//
//	const float* fl = (float*)&num;
//	printf("%d\n%u\n%.6f\n%.4g\n", num, num, *fl, *fl);
//
//	return 0;
//}

#include <stdio.h>

int main(void)
{
	int input = 0;
	int* int_input_address = &input;
	float* float_input_address = &input;



	return 0;
}