//
// Created by xiexu on 2022/11/4.
//

#include <stdio.h>
#include <math.h>

double self_seng_method(double a, double b, double bias, int n, int p, int* a_array);
double seng_method(double a, double b, int n, int p, const int* a_array);
double function(double num, int n, int p, const int* a_array);

int main(void)
{
	int n = 0;
	int p = 0;
	int a_array[21] = { 0 };
	double a = 0;
	double b = 0;
	double bias = 0.0001;

	scanf("%d%d", &n, &p);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d", a_array + i);
	}
	scanf("%lf%lf", &a, &b);

	double test = self_seng_method(a, b, bias, n, p, a_array);
	printf("%lf\n", test);

	return 0;
}

double self_seng_method(double a, double b, double bias, int n, int p, int* a_array)
{
	double mid = (a + b) / 2.0;
	double tmp_result = seng_method(a, mid, n, p, a_array) + seng_method(mid, b, n, p, a_array);
	double tmp_result_difference = seng_method(a, b, n, p, a_array);

	if (fabs(tmp_result - tmp_result_difference) <= 15 * bias)
		return tmp_result + (tmp_result - tmp_result_difference) / 15.0;
	else
		return self_seng_method(a, mid, bias / 2.0, n, p, a_array)
			+ self_seng_method(mid, b, bias / 2.0, n, p, a_array);
}

double seng_method(double a, double b, int n, int p, const int* a_array)
{
	double tmp = (4 * function((a + b) / 2.0, n, p, a_array) + function(a, n, p, a_array) + function(b, n, p, a_array))
		* (b - a) / 6.0;
//	printf("%lf ", tmp);
	return tmp;

}

double function(double num, int n, int p, const int* a_array)
{
	double half_result = 0;
	double num_pow_result = 1;
	for (int i = 0; i <= n; i++)
	{
		half_result += a_array[i] * num_pow_result;
		num_pow_result *= num;
	}
	return pow(half_result, p);
}

//1 1
//0 1
//0 2
