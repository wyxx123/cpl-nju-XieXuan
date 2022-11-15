//
// Created by xiexu on 2022/10/23.
//
#define TIME 3

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

//some question : not good naming!!!


//testing-----------------------------------------------------------------------------

//char putin[102][102] = { 0 };

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

int test(int n, char input[102][102], char return_pointer[102][102])// char* (*) [10]
{

	char output[102][102] = { 0 };
	//output:memory of output

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
					if (input[new_i][new_j] == '*')//err
					{
						count++;
					}
				}
				assert(count < 9);
				output[i][j] = (char)count + '0';
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//printf("%c", output[i][j]);
			return_pointer[i][j] = output[i][j];
		}
		if (i != n)
		{
			//printf("\n");
		}
	}

	return 0;
}

/*
 * 1 *
 * * 1
 *
 *
 *
 *
 */


void check(int n, char output[102][102], unsigned short seed)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (output[i][j] != '*')
			{
				//count the neighbor
				int count = 0;
				for (int k = 0; k < 8; k++)
				{
					int new_i = i + venture[k][0];
					int new_j = j + venture[k][1];
					if (output[new_i][new_j] == '*')
					{
						count++;
					}
				}
				if ((count + 0x30 != output[i][j]) && (output[i][j] != 'o'))
				{
					printf("fall in seed %u", seed);
					exit(1);
				}
			}
		}
	}
}

/*
 *
 * unsigned short seed
 * for(seed = 0; seed <= 0xffff ; seed++)
 * //build one_back_crime
 * for(int k =0 < 16)
 *  int bit = (seed & 1 <<k) >>k
 * if(bit == 1)
 *  ->'*'
 *  -> 'o'
 */


int main(void)
{
	char output[102][102] = { 0 };
	int n = TIME; // 4 first
	char input[102][102] = { 0 };
	unsigned short seed = 0;

	for (seed = 0; seed <= pow(2, n * n); seed++)
	{
		for (int i = 0; i < n * n; i++)
		{
			int bit = (seed & (1 << i)) >> i;
			if (bit == 0)
			{
				input[1 + (i / n)][1 + (i % n)] = 'o';
			}
			else
			{
				input[1 + (i / n)][1 + (i % n)] = '*';
			}
		}

		test(n, input, output);

		check(n, output, seed);

	}

	return 0;
}



//	int n = 0;
//	scanf("%d ", &n);

//	char one_back_crime[102][102] = { 0 };
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			scanf(" %c", &one_back_crime[i][j]);
//		}
//		//getchar();
//	}
//getchar();
