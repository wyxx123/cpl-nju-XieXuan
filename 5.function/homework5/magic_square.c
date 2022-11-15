//
// Created by xiexu on 2022/10/28.
//

/*
 * int n
 * scanf n
 * int square[1000][1000] ={};
 * int x ,y;
 *
 *
 * FillSquare(i,square[1000][1000],int* pointer_x,``y,n)
 *  Deduce (p_x,p_y,n);
 *
 *  square[*p_x][*p_y] = i;
 *
 *  Deduce(int* p_x,``,int n,int square[1000][1000])
 *    *p_x++;``;
 *
 *    if(p_x > n-1)
 *    p_x -= n;
 *    ``
 *
 *    if(s[p_x][p_y] !=0)
 *    *p_x --;
 *    *p_y -=2;
 *
 *
 *
 *
// *  if(i == 1)
// *  square[0][i/2] = i;
// *  else if()
 *
 *
 * for(if1 <= n*n)
 *   if(i == 1)
 *   x = 0;y = n/2;
 *   square[x][y] = i;
 *   else
 *   FillSquare(i,square,&x,&y,n)
 *
 * PrintSquare(square)
 *
 *
 */
#define MAX 1000

#include <stdio.h>

void FillSquare(int i, int square[MAX][MAX], int* pointer_row, int* pointer_col, int n);
void Deduce_position(int* pointer_row, int* pointer_col, int n, int square[MAX][MAX]);
void Modify_parameter(int n, int* pointer);
void PrintSquare(int square[MAX][MAX], int n);

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int square[MAX][MAX] = { 0 };
	int row = 0;
	int col = 0;

	for (int i = 1; i <= n * n; i++)
	{
		if (i == 1)
		{
			row = 0;
			col = n / 2;
			square[row][col] = i;
		}
		else
			FillSquare(i, square, &row, &col, n);
	}

	PrintSquare(square, n);

	return 0;
}

void FillSquare(int i, int square[MAX][MAX], int* pointer_row, int* pointer_col, int n)
{
	Deduce_position(pointer_row, pointer_col, n, square);
	square[*pointer_row][*pointer_col] = i;
}

void Deduce_position(int* const pointer_row, int* const pointer_col, int n, int square[MAX][MAX])
{
//	int* pro_p_row = pointer_row;
//	int* pro_p_col = pointer_col;

	(*pointer_col)++;
	(*pointer_row)--;

	Modify_parameter(n, pointer_row);
	Modify_parameter(n, pointer_col);

	if (square[*pointer_row][*pointer_col] != 0)
	{

		(*pointer_col)--;
		(*pointer_row) += 2;

		Modify_parameter(n, pointer_row);
		Modify_parameter(n, pointer_col);
	}
}

void Modify_parameter(int n, int* pointer)
{

	if (*pointer > n - 1)
		*pointer -= n;

	if (*pointer < 0)
		*pointer += n;
}

void PrintSquare(int square[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", square[i][j]);
		}
		printf("\n");
	}
}
