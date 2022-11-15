//
// Created by xiexu on 2022/10/21.
//

/*
 * int n = 0;
 * scanf
 *
 * char one_back_crime [102][102]={0};
 *
 * for(i=1;i<= n)
 *   for(j=1;j<= n)
 *   scanf(char[i][j])
 *
 * char output[102][102] = {0};
 *  // do output
 *  int venture[8][2] ={{-1,-1},{-1,0},{-1,1}{}{}{}{}{}}
 * for(i=1;i<= n)
 *   for(j=1;j<= n)
 *   if(one_back_crime[i][j] == '*' )
 *     output[i][j] = '*'
 *   else
 *     int count = 0;
 *     for(int k = 0; k<8)
 *        int new_i = venture [k] [0];
 *         ~
 *         if(one_back_crime [][] == '*')
 *         ++
 *      output[][] = count;
 *
 *
 *
 *  //output
 * for(i=1;i<= n)
 *   for(j=1;j<= n)
 *   {
 *         printf(output[i][j])
 *
 *   }
 *   printf("\n")
 *
 *
 */


//共性问题
//使用方向向量

#include <stdio.h>

int main(void)
{
	int n = 0;
	scanf("%d ", &n);

	char input[102][102] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c", &input[i][j]);
		}
		//getchar();
	}
	//getchar();

	char output[102][102] = { 0 };
	const int venture[8][2] =
		{
			{ -1, -1 },
			{ -1, 0 },
			{ -1, 1 },
			{ 0, -1 },
			{ 0, 1 },
			{ 1, -1 },
			{ 1, 0 },
			{ 1, 1 }
		};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (input[i][j] == '*')
			{
				output[i][j] = '*';
			}
			else
			{
				int count = 0;
				for (int k = 0; k < 8; k++)
				{
					int new_i = i + venture[k][0];
					int new_j = j + venture[k][1];
					if (input[new_i][new_j] == '*')
					{
						count++;
					}
				}
				output[i][j] = count + '0';
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%c", output[i][j]);
		}
		if (i != n)
		{
			printf("\n");
		}
	}

	return 0;
}