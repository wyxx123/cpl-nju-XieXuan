//
// Created by xiexu on 2022/11/18.
//



#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int board[6][SIZE][SIZE] = { 0 };

void LineRotate(int* array1, int* array2, int* array3, int* array4, int size_of_array);
void ArrayCopy(int* dest_array, const int* source_array, int size);
void Rotate(int array[SIZE][SIZE], int size);
void SwiftInt(int* num1, int* num2, int* num3, int* num4);

int main(void)
{
	char input[20] = { 0 };
	scanf("%19s", input);
	bool is_rotate = (input[0] == 'r');

	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &board[i][j][k]);
			}
		}
	}

	if (is_rotate)
	{
		int sequence_of_surface = 0;
		scanf("%d", &sequence_of_surface);
		Rotate(board[sequence_of_surface], n);
	}
	else
	{
		int face_num[4] = { 0 };
		int row_num[4] = { 0 };

		for (int i = 0; i < 4; i++)
		{
			scanf("%d%d", face_num + i, row_num + i);
		}

		LineRotate(board[face_num[0]][row_num[0]], board[face_num[1]][row_num[1]],
			board[face_num[2]][row_num[2]], board[face_num[3]][row_num[3]], n);
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d ", board[i][j][k]);
			}
			printf("\n");
		}
	}

	return 0;
}

void LineRotate(int* array1, int* array2, int* array3, int* array4, int size_of_array)
{
	int tmp_array[SIZE] = { 0 };
	ArrayCopy(tmp_array, array4, size_of_array);
	ArrayCopy(array4, array3, size_of_array);
	ArrayCopy(array3, array2, size_of_array);
	ArrayCopy(array2, array1, size_of_array);
	ArrayCopy(array1, tmp_array, size_of_array);
}

void ArrayCopy(int* dest_array, const int* source_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		dest_array[i] = source_array[i];
	}
}

void Rotate(int array[SIZE][SIZE], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int element_l_u = array[i][i];
		int element_l_d = array[size - 1 - i][i];
		int element_r_u = array[i][size - 1 - i];
		int element_r_d = array[size - 1 - i][size - 1 - i];

		for (int j = size - 2 * i - 3; j >= 0; j--)
		{
			SwiftInt(&array[i][i + 1 + j],
				&array[i + 1 + j][size - 1 - i],
				&array[size - 1 - i][size - 2 - i - j],
				&array[size - 2 - i - j][i]);
		}

		array[size - 1 - i][size - 1 - i] = element_r_u;
		array[i][size - 1 - i] = element_l_u;
		array[size - 1 - i][i] = element_r_d;
		array[i][i] = element_l_d;

	}
}

void SwiftInt(int* num1, int* num2, int* num3, int* num4)
{
	int tmp = *num4;
	*num4 = *num3;
	*num3 = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

//建议使用define
//数组开小了


/*
37 68 44
14 54 14
85 31 94
 */



/*
4 13 15
32 73 51 =
32 67 57

9 94 67
53 40 38
42 75 77

85 0 33
95 65 15 =
87 35 42

10 56 35 =
72 46 89
93 44 97

59 47 95 =
96 6 19
60 52 86

75 69 26
34 73 93
94 45 61


line-rotate 4
 1 1 1 1 1 1 1
 1 1 2 1
 1 1 1 1
 1 1 1 1
 2 2 2 2
 2 2 2 2
 2 2 2 2
 2 2 2 2
 3 3 3 3
 3 3 3 3
 3 3 3 3
 3 3 3 3
 4 4 4 4
 4 4 4 4
 4 4 4 4
 4 4 4 4
 5 5 5 5
 5 5 5 5
 5 5 5 5
 5 5 5 5
 6 6 6 6
 6 6 6 6
 6 6 6 6
 6 6 6 6
 0 1
 0 0
 2 1
 5 1

rotate 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
3 3 3 3 3 3 3 3 3 3
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 6
6 6 6 6 6 6 6 6 6 1
5

 */




