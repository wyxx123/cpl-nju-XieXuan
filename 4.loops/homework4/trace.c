//
// Created by xiexu on 2022/10/21.
//

/*
 * char map[52][52] = {0};
 * int n = 0;
 * int m = 0;
 * int x = 0;
 * int y = 0;
 *
 * scanf("%d%d%d%d,	n,m,x,y);
 *
 * for1 for1 scanf
 *
 * int if_continue = 1
 * while(if_continue)
 * 1.printf
 * int bias[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}
 * 2.find a (#) place
 * for(int i = 0, <4)
 *   int new_x = x+bias[i][0]
 *   int new_y = y+bias[i][1]
 *   if(map[][] == '#')
 *   map[x][y] = '&'
 *   x = new_x
 *   y = new_y  ->1
 * if(x != new_x && y != new_y)
 *   if_continue = 0
 *
 */

//2500

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	char map[52][52] = { 0 };
	int n = 0;
	int m = 0;
	int x = 0;
	int y = 0;
	int x_array[2500] = { 0 };
	int y_array[2500] = { 0 };

	scanf("%d%d%d%d", &n, &m, &x, &y);
	//getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}

	bool if_continue = true;
	int count = 0;
	int bias[4][2] =
		{
			{ 1, 0 },
			{ 0, 1 },
			{ -1, 0 },
			{ 0, -1 }
		};
	while (if_continue)
	{
		//print_array
		x_array[count] = x;
		y_array[count] = y;

		//find a(#) place
		bool is_move = false;
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + bias[i][0];
			int new_y = y + bias[i][1];
			if (map[new_x][new_y] == '#')
			{
				map[x][y] = '&';
				x = new_x;
				y = new_y;
				count++;
				is_move = true;
				break;
			}
		}

		if (is_move == false)
		{
			if_continue = false;
		}
	}

	//printf
	count++;
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%d %d\n", x_array[i], y_array[i]);
	}

	return 0;
}