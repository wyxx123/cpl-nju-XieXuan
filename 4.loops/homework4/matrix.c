//
// Created by xiexu on 2022/10/22.
//

/*
 * scanf(m,n,p)
 * arr_a[m][n]  //100 100
 * arr_b[n][p]
 * arr_c[m][p]
 *
 * //count
 * for(int i = 0 ;< m)
 *  for(int j = 0 ; < p)
 *
 * int count = 0
 *  for(k;<n)
 *  count += arr_a[i][k]*arr_b[k][j]
 *
 * printf(%d )
 *}
 * printf(\n)
 *}
 *
 */



#include <stdio.h>

int main(void)
{
	int m = 0;
	int n = 0;
	int p = 0;
	scanf("%d%d%d", &m, &n, &p);

	int arr_a[100][100] = { 0 };
	int arr_b[100][100] = { 0 };
	//int arr_c[100][100] = { 0 };

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr_a[i][j]);//err: 变量or常量
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p; j++)
		{
			scanf("%d", &arr_b[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < p; j++)
		{
			int count = 0;
			for (int k = 0; k < n; k++)
			{
				count += arr_a[i][k] * arr_b[k][j];
			}
			printf("%d ", count);
		}
		printf("\n");
	}

	return 0;
}