//
// Created by xiexu on 2022/12/9.
//
#include <stdio.h>

//阶数
#define MAX_DEGREE 20010
#define MAX_LENGTH_VARIABLE 15

typedef struct formula
{
	int degree;
	int array_of_tie[MAX_DEGREE];
} Formula;

Formula for1 = { 0 };
Formula for2 = { 0 };
Formula add_for = { 0 };
Formula sub_for = { 0 };
Formula mul_for = { 0 };

char variable[MAX_LENGTH_VARIABLE] = { 0 };

void AddFormula(void);
void SubFormula(void);
void Mulformula(void);
void PrintFormula(Formula input_formula);

int main(void)
{
	scanf("%d%d%20s", &for1.degree, &for2.degree, variable);

	for (int i = for1.degree; i >= 0; i--)
	{
		scanf("%d", &for1.array_of_tie[i]);
	}

	for (int i = for2.degree; i >= 0; i--)
	{
		scanf("%d", &for2.array_of_tie[i]);
	}

	//add
	AddFormula();
	SubFormula();
	Mulformula();

	PrintFormula(add_for);
	PrintFormula(sub_for);
	PrintFormula(mul_for);

	return 0;
}

void AddFormula(void)
{
	int max_degree = (for1.degree > for2.degree) ? for1.degree : for2.degree;
	add_for.degree = max_degree;

	for (int i = 0; i <= max_degree; i++)
	{
		add_for.array_of_tie[i] = for1.array_of_tie[i] + for2.array_of_tie[i];
	}
}

void SubFormula(void)
{
	int max_degree = (for1.degree > for2.degree) ? for1.degree : for2.degree;
	sub_for.degree = max_degree;

	for (int i = 0; i <= max_degree; i++)
	{
		sub_for.array_of_tie[i] = for1.array_of_tie[i] - for2.array_of_tie[i];
	}
}

void Mulformula(void)
{
	mul_for.degree = for1.degree + for2.degree;

	for (int i = 0; i <= for1.degree; i++)
	{
		for (int j = 0; j <= for2.degree; j++)
		{
			int term_degree = i + j;

			mul_for.array_of_tie[term_degree] +=
				for1.array_of_tie[i] * for2.array_of_tie[j];
		}
	}
}

void PrintFormula(Formula input_formula)
{
	for (int i = input_formula.degree; i >= 0; i--)
	{
		if (i != input_formula.degree && input_formula.array_of_tie[i] > 0)
			printf("+");

		if (input_formula.array_of_tie[i] != 0 && i != 0
			&& input_formula.array_of_tie[i] == -1)
			printf("-");

		if (input_formula.array_of_tie[i] != 0
			&& (i == 0 || (input_formula.array_of_tie[i] != 1
				&& input_formula.array_of_tie[i] != -1)))
		{
			printf("%d", input_formula.array_of_tie[i]);
		}

		if (i != 0 && input_formula.array_of_tie[i] != 0)
			printf("%s", variable);

		if (i != 0 && i != 1 && input_formula.array_of_tie[i] != 0)
			printf("^%d", i);
	}

	printf("\n");
}

//这题出的数据范围有问题吧。。。




