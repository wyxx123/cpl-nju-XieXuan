//
// Created by xiexu on 2023/2/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max(a, b) ((a)>(b)? (a): (b))
#define min(a, b) ((a)<(b)? (a): (b))
#define chkmax(a, b) (a=max(a, b))
#define chkmin(a, b) (a=min(a, b))
#define debug1 puts("lg1")
#define debug2 puts("lg2")
#define debug3 puts("lg3")
#define debug4 puts("lg4")
#define debug5 puts("lg5")
#define debug puts("lg")

#define N 2500

int n, m, d;
int num[N][N], sum[N][N];

int f(int x, int y, int len)
{
	return sum[x][min(m, y + len)] - sum[x][max(0, y - len - 1)];
}
int calc(int x, int y)
{
	int mn = max(x - d, 1), mx = min(x + d, n);
	int rem = 0;
	for (int i = mn; i <= mx; i++)
	{
		rem += f(i, y, d - abs(x - i));
	}
	// printf("%d ", rem);
	return rem;
}
/*
4 6 1
-3 4 5 4 3 2
1 6 1 7 5 2
9 9 0 0 8 -3
8 8 4 4 -3 2
*/
int cnt, pos[2500000][2];
long long res;
int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &num[i][j]);
			sum[i][j] = sum[i][j - 1] + num[i][j];
		}
	}
	res = -0x7fffffff;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int rem = calc(i, j);
			if (rem > res)
			{
				res = rem;
				cnt = 0;
				pos[++cnt][0] = i;
				pos[cnt][1] = j;
			}
			else if (rem == res)
			{
				pos[++cnt][0] = i;
				pos[cnt][1] = j;
			}
		}
	}
	printf("%lld %d\n", res, cnt);
	for (int i = 1; i <= cnt; i++) printf("%d %d\n", pos[i][0], pos[i][1]);
}