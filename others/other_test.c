//#define 一只最强的9 0
//#define ⑨ void

//
// Created by ⑨ on 9999/99/99.
//
//
//int main(⑨)
//{
//	printf("%s\n","⑨是最强的！！！");
//	return 一只最强的9;
//}




#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int main(void)
{
	int* array1 = malloc(ROW * COL * sizeof(*array1));
	int(* array2)[COL] = malloc(ROW * COL * sizeof(**array2));
	int(* array3)[COL] = malloc(ROW * sizeof(*array3));

	array3[10][10] = 0;
	printf("%d\n", array3[10][10]);

	free(array1);
	free(array2);
	free(array3);
	return 0;
}






