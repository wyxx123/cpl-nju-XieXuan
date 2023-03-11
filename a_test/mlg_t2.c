//
// Created by xiexu on 2023/2/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a)>(b)? (a): (b))
#define min(a, b) ((a)<(b)? (a): (b))
#define chkmax(a, b) (a=max(a, b))
#define chkmin(a, b) (a=min(a, b))

#define N 210005
#define M 300
int T;
int n;
char s[N], t[N];
int rem[N];
bool used[M];

bool Isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool Isletter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool equal(int x, int y)
{
	return ((x % 10) == (y / 10)) && ((x / 10) == (y % 10));
}

bool solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	memset(used, false, sizeof used);
	int len = strlen(t + 1);
	int now = 0;
	for (int i = 1; i <= len; i++)
	{
		if (Isdigit(t[i]))
		{
			if (!Isdigit(t[i + 1])) return false;
			rem[++now] = 10 * (t[i] - '0') + t[i + 1] - '0';
			i++;
		}
		else if (Isletter(t[i]))
		{
			rem[++now] = 100 + t[i];
		}
		else return false;
	}
	if (now != n) return false;
	int tmp;
	for (int i = 1, j = n; i <= j; i++, j--)
	{
		if (s[i] != '?' || s[j] != '?')
		{
			if (s[i] != '?') tmp = 100 + s[i];
			else tmp = 100 + s[j];
			if (rem[i] != tmp || rem[j] != tmp) return false;
		}
		else
		{
			if (rem[i] > 100 || rem[j] > 100) return false;
			if (!equal(rem[i], rem[j])) return false;

			if (!used[rem[i]]) used[rem[i]] = true;
			else if (!used[rem[j]]) used[rem[j]] = true;
			else return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		if (solve()) printf("Correct. \n");
		else printf("Wrong Answer! \n");
	}
	return 0;
}
