//
// Created by xiexu on 2022/10/24.
//
#include <stdio.h>

int i = 0;
int n = 0;
int t = 0;

int Function0(int o);
int Function1(int o);
int Function2(int o);
int Function3(int o);

int main(void)
{
	int s0 = 0;

	int o = 0;

	scanf("%d%d%d%d%d", &s0, &i, &n, &t, &o);

	if (s0 == 0)
		printf("%d", Function0(o));
	if (s0 == 1)
		printf("%d", Function1(o));
	if (s0 == 2)
		printf("%d", Function2(o));
	if (s0 == 3)
		printf("%d", Function3(o));

	return 0;
}

int Function0(int o)
{
	if (o == i)
		return 1;
	return 0;
}

int Function1(int o)
{
	if (o == n)
		return 2;
	if (o == i)
		return 1;
	return 0;
}

int Function2(int o)
{
	if (o == i)
		return 1;
	if (o == t)
		return 3;
	return 0;

}

int Function3(int o)
{
	if (o == i)
		return 1;
	return 0;
}
