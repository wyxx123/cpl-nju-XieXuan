//
// Created by xiexu on 2022/10/25.
//


/*
 *
 * limit : 1,1-3,3(a,b) 5,5(c)
 * for*6
 * if(a!=c||b!=d)&&...
 *
 * how to test:???
 * 1.input - in "main" - location[6]
 * 2.output - distance = ~ ==> distance-全局变量
 *          - method[10]  => char_print ->print=>  "= method[i]" ==>output-全局变量
 *          - if the obstacle has some effect on the chose of method?
 *          --> if-> method[0]//others-> method[(i+1)++]
 * 3.check - (location)
 *         - x = location[0] y = location[1]
 *         - if(method[0] == 0) method++;
 *         - for(int i = 0 ; < distance)
 *           if( == 'L') x--
 *           ...R
 *           ...U
 *           ...D
 *           if(x == location[4] && y == location[5])
 *           exit(9)//9-obstacles
 *
 *           if()
 *           exit(6)//6-not fit
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int distance = 0;
char method[10] = { 0 };
int count_method_char_sequence = 0;

int char_printf(int n, char output)
{
	for (int i = 0; i < n; i++)
	{
		//printf("%c", output);
		//method[+1]:output

		method[count_method_char_sequence + 1] = output;
		count_method_char_sequence++;
	}
}

void function(const int* loc, int delta_x, int delta_y)
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

int test(int location[6])
{
//	int location[6] = { 0 };
//  define --> main

//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", location + i);
//	}
// input-->main

	int delta_x = abs(location[0] - location[2]);
	int delta_y = abs(location[1] - location[3]);

	if ((location[0] == location[2]) && (location[0] == location[4])// xa 0  ya 1  xb 2  yb 3  xc 4  yc 5
		&& (compare((location[1] - location[5]), (location[3] - location[5])) < 0))
	{
		//printf("%d\n", delta_y + delta_x + 2);
		//->distance:output

		distance = delta_x + delta_y + 2;

		//printf("R");
		//->method[0]:output(the one that need considering personally)

		method[0] = 'R';

		location[0]++;
		function(location, delta_x + 1, delta_y);
		location[0]--;
	}
	else if ((location[1] == location[3]) && (location[3] == location[5])
		&& (compare((location[0] - location[4]), (location[2] - location[4])) < 0))
	{
		//printf("%d\n", delta_y + delta_x + 2);
		//->distance:output

		distance = delta_x + delta_y + 2;

		//printf("U");
		//->method[0]:output(the one that need considering personally)

		method[0] = 'U';

		location[1]++;
		function(location, delta_x, delta_y + 1);
		location[1]--;
	}
	else
	{
		//printf("%d\n", delta_y + delta_x);
		//->distance:output

		distance = delta_x + delta_y;

		function(location, delta_x, delta_y);
	}
}

//<!- printf fault function->
void printf_print_fault(const int* location)
{
	printf("fail in:");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", location[i]);
	}
}

//<-! check function ->
void check(const int* location)
{
	int x = location[0];
	int y = location[1];

	const char* method_check = method;
	if (method[0] == 0)
	{
		method_check++;
	}

	for (int i = 0; i < distance; i++)
	{
		if (method_check[i] == 'L')
		{
			x--;
		}
		else if (method_check[i] == 'R')
		{
			x++;
		}
		else if (method_check[i] == 'U')
		{
			y++;
		}
		else if (method_check[i] == 'D')
		{
			y--;
		}
		else
		{
			printf_print_fault(location);
			exit(10);
		}

		if (x == location[4] && y == location[5])
		{
			printf_print_fault(location);
			exit(9);
		}
	}

	if (x != location[2] || y != location[3])
	{
		printf_print_fault(location);
		exit(6);
	}

}

int main(void)
{
	for (int a = 1; a <= 3; a++)
		for (int b = 1; b <= 3; b++)
			for (int c = 1; c <= 3; c++)
				for (int d = 1; d <= 3; d++)
					for (int e = 0; e <= 4; e++)
						for (int f = 0; f <= 4; f++)
							if ((a != c || b != d) && (c != e || d != f) && (a != e || b != f))
							{
								int location[6] = { 0 };

								location[0] = a;
								location[1] = b;
								location[2] = c;
								location[3] = d;
								location[4] = e;
								location[5] = f;

								//a==2&&b==1&&c==1&&d==2&&e==1&&f==1

								test(location);

								check(location);

								memset(method, 0, 10);
								distance = 0;
								count_method_char_sequence = 0;
							}
	return 0;
}
