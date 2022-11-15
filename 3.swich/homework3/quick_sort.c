//
// Created by xiexu on 2022/10/15.
//

/*
 * do
 * e.g. left
 * int l;
 * do
 *l++
 * while(one_back_crime[i]<mid)
 *  e.g.right
 * int r;
 * do
 *l--
 * if(one_back_crime[i]==mid)
 * flag = i
 * while(one_back_crime[i]>=mid)
 *
 * //swap
 * if(left > right)
 * swap()
 *
 * while(left>right)
 *
 *
 * 1 2 3 4 5* 6 7
 *
 * swap (left , flag);
 *
 */



#include <stdio.h>

void all_swap(int* num1, int* num2)
{
	int swap = *num1;
	*num1 = *num2;
	*num2 = swap;
}

int main(void)
{
	int n = 0;
	int k = 0;
	int input[100001] = { 0 };
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", input + i);
	}

	int mid = input[k];
	int l = 1;
	int r = n;
	int flag = 0;
	do
	{
		//left
		while (input[l] < mid)
		{
			l++;
		}


		//right
		while (input[r] >= mid)
		{
			if (input[r] == mid)
			{
				flag = r;
			}
			r--;
		}

		//swap
		if (l < r)
		{
			all_swap(input + l, input + r);
		}

	} while (l < r);

	//last swap
	all_swap(input + l, input + flag);

	//print
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", input[i]);
	}

	return 0;
}