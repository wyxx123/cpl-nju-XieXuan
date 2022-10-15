//
// Created by xiexu on 2022/10/7.
//



//int main(void)
//{
//	int input[20000] = { 0 };
//	int n = 0;
//	int flag[20000] = { 0 };
//	int this;
//	scanf("%d", &n);
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		scanf("%d", input + i);
//	}
//
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		this = flag[i];
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int input[200000] = { 0 };
//	int n = 0;
//	int flag[] = { 0 };
//
//	scanf("%d", &n);
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		scanf("%d", input + i);
//	}
//
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		flag[input[i]]++;
//	}
//
//	for (int i = 0; i < ; i++)
//	{
//		if (flag[i] == 1)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//#define _mod 10007
//
//int main(void)
//{
//	int input = 0;
//	int half_result = 1;
//	int result = 0;
//
//	scanf("%d", &input);
//
//	for (int i = 1; i <= input; i++)
//	{
//		half_result *= i % _mod;
//		half_result %= _mod;
//		result += half_result % _mod;
//	}
//
//	printf("%d\n", result % _mod);
//
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main(void)
//{
//	int n = 0;
//	long double x = 0;
//	long double output = 0;
//
//	scanf("%Lf%d", &x, &n);
//	for (int i = 0; i <= n; i++)
//	{
//		output += powl(-1, i) * powl(x, 2 * i + 1) / (2 * i + 1);
//	}
//	printf("%.10Lf", 4 * output);
//	return 0;
//}

//int main(void)
//{
//	int n = 0;
//	double x = 0;
//	double output = 0;
//	int sign = 1;
//
//	scanf("%lf%d", &x, &n);
//	for (int i = 0; i < n; i++)
//	{
//		output += sign * pow(x, 2 * i + 1) / (2 * i + 1);
//		sign *= -1;
//	}
//	printf("%.10f", 4 * output);
//	return 0;
//}

//#include <stdio.h>
//
//int collf(int n)
//{
//	if (n % 2 == 0)
//	{
//		return n / 2;
//	}
//	else
//	{
//		return 3 * n + 1;
//	}
//}
//
//int main(void)
//{
//	int n = 0;
//	int max = 0;
//	int times = 0;
//
//	scanf("%d", &n);
//
//	max = n;
//	while (n - 1)
//	{
//		n = collf(n);
//		if (n > max)
//		{
//			max = n;
//		}
//		times++;
//	}
//
//	printf("%d %d\n", times, max);
//	return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int char_printf(int n, char output)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%c", output);
//	}
//}
//
//void function(int* loc, int delta_x, int delta_y)
//{
//
//	if (loc[4] == loc[0] || loc[5] == loc[3])
//	{
//		char_printf(delta_x, (loc[0] > loc[2]) ? 'L' : 'R');
//		char_printf(delta_y, (loc[1] > loc[3]) ? 'D' : 'U');
//	}
//	else
//	{
//		char_printf(delta_y, (loc[1] > loc[3]) ? 'D' : 'U');
//		char_printf(delta_x, (loc[0] > loc[2]) ? 'L' : 'R');
//	}
//}
//
//int main(void)
//{
//	int location[6] = { 0 };
//
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", location + i);
//	}
//
//	int delta_x = abs(location[0] - location[2]);
//	int delta_y = abs(location[1] - location[3]);
//
//	if ((location[0] == location[2]) && (location[0] == location[4])
//		&& (location[1] - location[5]) * (location[3] - location[5]) < 0)
//	{
//		printf("%d\n", delta_y + delta_x + 2);
//		printf("R");
//		location[0]++;
//		function(location, delta_x, delta_y);
//		printf("L");
//	}
//	else if ((location[1] == location[3]) && (location[3] == location[5])
//		&& (location[0] - location[4]) * (location[2] - location[4]) < 0)
//	{
//		printf("%d\n", delta_y + delta_x + 2);
//		printf("U");
//		location[1]++;
//		function(location, delta_x, delta_y);
//		printf("D");
//	}
//	else
//	{
//		printf("%d\n", delta_y + delta_x);
//		function(location, delta_x, delta_y);
//	}
//}


//#include <stdio.h>
//
//void my_swap(int size, char array[])
//{
//	for (int i = 0; i < size / 2; i++)
//	{
//		char tem = array[i];
//		array[i] = array[size - 1 - i];
//		array[size - 1 - i] = tem;
//	}
//}
//
//int main(void)
//{
//	int size = 0;
//	char array[10000] = { 0 };//1e7
//	int point = 0;
//	char none = 0;
//	scanf("%d", &size);
//	scanf("%c", &none);
//	for (int i = 0; i < size; i++)
//	{
//		scanf("%c", array + i);
//	}
//	scanf("%d", &point);
//
//	my_swap(point, array);
//	my_swap(size - point, array + point);
//
//	for (int i = 0; i < size; i++)
//	{
//		printf("%c", array[i]);
//	}
//
//	return 0;
//}

//
//#include <stdio.h>
//
//int main(void)
//{
//	int input[200000] = { 0 };
//	int n = 0;
//	int flag[10000] = { 0 };
//
//	scanf("%d", &n);
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		scanf("%d", input + i);
//	}
//
//	for (int i = 0; i < 2 * n - 1; i++)
//	{
//		flag[input[i]]++;
//	}
//
//	for (int i = 1; i < 10000; i++)
//	{
//		if (flag[i] == 1)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int char_printf(int n, char output)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%c", output);
//	}
//}
//
//void function(int* loc, int delta_x, int delta_y)
//{
//
//	if (loc[4] == loc[0] || loc[5] == loc[3])  // xa 0  ya 1  xb 2  yb 3  xc 4  yc 5
//	{
//		char_printf(delta_x, (loc[0] > loc[2]) ? 'L' : 'R');
//		char_printf(delta_y, (loc[1] > loc[3]) ? 'D' : 'U');
//	}
//	else
//	{
//		char_printf(delta_y, (loc[1] > loc[3]) ? 'D' : 'U');
//		char_printf(delta_x, (loc[0] > loc[2]) ? 'L' : 'R');
//	}
//}
//
//int main(void)
//{
//	int location[6] = { 0 };
//
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", location + i);
//	}
//
//	int delta_x = abs(location[0] - location[2]);
//	int delta_y = abs(location[1] - location[3]);
//
//	if ((location[0] == location[2]) && (location[0] == location[4])// xa 0  ya 1  xb 2  yb 3  xc 4  yc 5
//		&& ((location[1] - location[5]) * (location[3] - location[5]) < 0))
//	{
//		printf("%d\n", delta_y + delta_x + 2);
//		printf("R");
//		location[0]++;
//		function(location, delta_x+1, delta_y);
//	}
//	else if ((location[1] == location[3]) && (location[3] == location[5])
//		&& ((location[0] - location[4]) * (location[2] - location[4]) < 0))
//	{
//		printf("%d\n", delta_y + delta_x + 2);
//		printf("U");
//		location[1]++;
//		function(location, delta_x, delta_y+1);
//	}
//	else
//	{
//		printf("%d\n", delta_y + delta_x);
//		function(location, delta_x, delta_y);
//	}
//}

#include <stdio.h>
#include <stdlib.h>

int char_printf(int n, char output)
{
	for (int i = 0; i < n; i++)
	{
		printf("%c", output);
	}
}

void function(int* loc, int delta_x, int delta_y)
{

	if (loc[4] == loc[0] || loc[5] == loc[3])  // xa 0  ya 1  xb 2  yb 3  xc 4  yc 5
	{
		char_printf(delta_x, (loc[0] > loc[2]) ? 'L' : 'R');
		char_printf(delta_y, (loc[1] > loc[3]) ? 'D' : 'U');
	}
	else
	{
		char_printf(delta_y, (loc[1] > loc[3]) ? 'D' : 'U');
		char_printf(delta_x, (loc[0] > loc[2]) ? 'L' : 'R');
	}
}

int compare(int num1, int num2)
{
	if ((num1 < 0 && num2 < 0) || (num1 > 0 && num2 > 0))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	int location[6] = { 0 };

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", location + i);
	}

	int delta_x = abs(location[0] - location[2]);
	int delta_y = abs(location[1] - location[3]);

	if ((location[0] == location[2]) && (location[0] == location[4])// xa 0  ya 1  xb 2  yb 3  xc 4  yc 5
		&& (compare((location[1] - location[5]), (location[3] - location[5])) < 0))
	{
		printf("%d\n", delta_y + delta_x + 2);
		printf("R");
		location[0]++;
		function(location, delta_x + 1, delta_y);
	}
	else if ((location[1] == location[3]) && (location[3] == location[5])
		&& (compare((location[0] - location[4]), (location[2] - location[4])) < 0))
	{
		printf("%d\n", delta_y + delta_x + 2);
		printf("U");
		location[1]++;
		function(location, delta_x, delta_y + 1);
	}
	else
	{
		printf("%d\n", delta_y + delta_x);
		function(location, delta_x, delta_y);
	}
}