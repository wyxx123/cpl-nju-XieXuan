//
// Created by xiexu on 2022/11/16.
//
#include <stdio.h>

int LeastTime(int a, int b, int c, int times);

int Pour(int a, int V, int b);

int Min(int a, int b, int c, int d, int e, int f);

int Va, Vb, Vc, a0, b0, c0;

int main(void)
{
	int k, a, b, c;
	scanf("%d%d%d%d%d%d%d%d%d%d", &k, &Va, &Vb, &Vc, &a, &b, &c, &a0, &b0, &c0);
	if ((a + b + c < a0 + b0 + c0) || a0 + b0 + c0 == 0)
		printf("No");
	else
	{
		if (LeastTime(a, b, c, 0) <= k)
			printf("Yes");
		else
			printf("No");
	}
	return 0;
}

int LeastTime(int a, int b, int c, int times)
{
	//final judge
	if (a == a0 && b == b0 && c == c0)
		return times;

	if ((a + b + c == a0 + b0 + c0) && a != 0 && b != 0 && c != 0)
		return times + 2;
	if (a + b + c == a0 + b0 + c0)
		return times + 1;
	if ((a + b + c) < (a0 + b0 + c0) || times > 10)
		return 11;
	return Min(LeastTime(Pour(b, Va, a), 0, c, times + 1),
		LeastTime(Pour(c, Va, a), b, 0, times + 1),
		LeastTime(0, Pour(a, Vb, b), c, times + 1),
		LeastTime(a, Pour(c, Vb, b), 0, times + 1),
		LeastTime(0, b, Pour(a, Vc, c), times + 1),
		LeastTime(a, 0, Pour(b, Vc, c), times + 1));
}

int Pour(int a, int V, int b)
{
	if (a + b >= V)
		b = V;
	else
		b = b + a;
	return b;
}

int Min(int a, int b, int c, int d, int e, int f)
{
	int arr[6] = { a, b, c, d, e, f };
	for (int i = 0; i < 5; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	return arr[0];
}
