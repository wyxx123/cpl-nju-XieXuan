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


//#include <stdio.h>
//
//int main(void)
//{
//	int num = 0;
//	int* int_num_ptr = &num;
//	float* float_num_ptr = &num;
//
//	char pre_input = 0;
//	char later_input = 0;
//	for (int i = 4; i >= 0; i++)
//	{
//		scanf("%c%c", &pre_input,&later_input);
//
//	}
//
//
//	return 0;
//}

//waiting for further thought.

//#include <stdio.h>
//#include <stdbool.h>
//
//int main(void)
//{
//	bool a = false;
//	bool b = true;
//
//	printf("%p %p\n", &a, &a + 1);
//	return 0;
//}

#include <stdio.h>

int main(void)
{
	int input = 0;
	float* fl_input = &input;

	scanf("%x", &input);
	printf("%d\n%u\n%.6f\n%.3e\n", input, input, *fl_input, *fl_input);

	return 0;
}

//好好看看sf，pf吧，哥。。。