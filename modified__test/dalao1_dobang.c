//
// Created by xiexu on 2022/12/10.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int T;
char s[21][21];

int check()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int rem = s[i][j] == '_' ? 0 : 1;
			if (!rem) continue;
			int flag = rem;
			for (int k = 1; k < 5; k++)
			{
				if (i + k >= 20 || s[i + k][j] != s[i][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag) return 1;
			flag = rem;
			for (int k = 1; k < 5; k++)
			{
				if (j + k >= 20 || s[i][j + k] != s[i][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag) return 1;
			flag = rem;
			for (int k = 1; k < 5; k++)
			{
				if (i + k >= 20 || j + k >= 20 || s[i + k][j + k] != s[i][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag) return 1;
			flag = rem;
			for (int k = 1; k < 5; k++)
			{
				if (i + k >= 20 || j - k < 0 || s[i + k][j - k] != s[i][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag) return 1;
		}
	}
	return 0;
}

int put()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (s[i][j] == '_')
			{
				s[i][j] = '*';
				if (check()) return 2;
				s[i][j] = '_';
			}
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (s[i][j] == '_')
			{
				s[i][j] = '*';
				int rem = 0;
				for (int k = 0; k < 20 && !rem; k++)
				{
					for (int l = 0; l < 20 && !rem; l++)
					{
						if (s[k][l] == '_')
						{
							s[k][l] = '#';
							if (check()) ++rem;
							s[k][l] = '_';
						}
					}
				}
				if (!rem) return 0;
				s[i][j] = '_';
			}
		}
	}
	return 1;
}

void solve()
{
	for (int i = 0; i < 20; i++) scanf("%s", s[i]);
	int res = put();
	if (res == 0) puts("Not Sure");
	else if (res == 1) puts("Win");
	else puts("Lose");
	return;
}

int main()
{
	//freopen("data.in", "r", stdin);
	scanf("%d", &T);
	while (T--) solve();
}