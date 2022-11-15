//
// Created by xiexu on 2022/11/12.
//


/*
 * 4 5 7  -- V
 *
 *
 *
 */


#include <stdio.h>
#include <stdbool.h>

bool is_operatable(int k, int Va, int Vb, int Vc, int a, int b, int c, int a0, int b0, int c0);

int main(void)
{
	int k = 0;
	int Va = 0;
	int Vb = 0;
	int Vc = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int a0 = 0;
	int b0 = 0;
	int c0 = 0;

	scanf("%d%d%d%d%d%d%d%d%d%d", &k, &Va, &Vb, &Vc, &a, &b, &c, &a0, &b0, &c0);

	if (is_operatable(k, Va, Vb, Vc, a, b, c, a0, b0, c0))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

bool is_operatable(int k, int Va, int Vb, int Vc, int a, int b, int c, int a0, int b0, int c0)
{
	if ((a + b + c) < (a0 + b0 + c0))
	{
		return false;
	}

	if ((a == a0) && (b == b0) && (c == c0))
	{
		return true;
	}

	if (k == 0)
	{
		return false;
	}

	bool a_to_b = false;
	bool a_to_c = false;
	bool b_to_a = false;
	bool b_to_c = false;
	bool c_to_a = false;
	bool c_to_b = false;
	if (a != 0)
	{
		a_to_b = is_operatable(k - 1, Va, Vb, Vc, 0, ((a + b > Vb) ? Vb : (a + b)), c, a0, b0, c0);
		a_to_c = is_operatable(k - 1, Va, Vb, Vc, 0, b, ((a + c > Vc) ? Vc : (a + c)), a0, b0, c0);
	}
	if (b != 0)
	{
		b_to_a = is_operatable(k - 1, Va, Vb, Vc, ((a + b > Va) ? Va : (a + b)), 0, c, a0, b0, c0);
		b_to_c = is_operatable(k - 1, Va, Vb, Vc, a, 0, ((b + c > Vc) ? Vc : (b + c)), a0, b0, c0);
	}
	if (c != 0)
	{
		c_to_a = is_operatable(k - 1, Va, Vb, Vc, ((a + c > Va) ? Va : (a + c)), b, 0, a0, b0, c0);
		c_to_b = is_operatable(k - 1, Va, Vb, Vc, a, ((b + c > Vb) ? Vb : (b + c)), 0, a0, b0, c0);
	}
	return (a_to_b || a_to_c
		|| b_to_a || b_to_c
		|| c_to_a || c_to_b);
}
