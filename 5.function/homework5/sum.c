//
// Created by xiexu on 2022/10/28.
//



/*
 * scanf t,n
 *
 * int count (int t, int i)
 *  if(i-- > 1)
 *  return t+count(t, i)*10;
 *return t;
 *
 * int sum
 * for(i = 1 ;<=n)
 * 1.count 'tt'  //fuc
 * 2.sum += count(n, i)
 *
 */


#include <stdio.h>

int count(int t, int i);

int main(void)
{
	int sum = 0;
	int t = 0;
	int n = 0;

	scanf("%d%d", &n, &t);

	for (int i = 1; i <= n; i++)
	{
		sum += count(t, i);
	}

	printf("%d\n", sum);
	return 0;
}

int count(int t, int i)
{
	if (i-- > 1)
	{
		return t + count(t, i) * 10;
	}
	return t;
}
