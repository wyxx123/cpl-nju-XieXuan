#include <stdio.h>
#include <math.h>

////变量：给定钱数（改），钱种类数列（50，20，10，5，1）
////首先一个循环(i=0;i<5;i++)
////  打印n/arr[i]
////  n=n%arr[i]
//
//int main()
//{
//    int money_format[] = { 50,20,10,5,1 };
//    int money = 0;
//    int i = 0;
//    scanf("%d", &money);
//    for (i = 0;i < 5;i++)
//    {
//        printf("%d\n", money / money_format[i]);
//        money = money % money_format[i];
//    }
//    return 0;
//}

#define PI = 3.14159

//
//int main()
//{
//	float result1 = 16 * atan(1.0 / 5.0) - 4 * atan(1.0 / 239.0);
//	float result2 = log(pow(640320, 3) + 744) / sqrt(163) * 1.0;
//	printf("%.15f\n", result1);
//	printf("%.15f\n", result2);
//	return 0;
//}

#include <stdio.h>

//int main(void)
//{
//	char month[15] = { 0 };
//	int day = 0;
//	int year = 0;
//	char weekday[15] = { 0 };
//	int hour, minute, second;
//	scanf("%s%d%d%s%d%d%d", &month, &day, &year, &weekday, &hour, &minute, &second);
//	printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d\n", weekday, month, day, hour, minute, second, year);
//
//	return 0;
//}
//int main(void)
//{
//	int one_back_crime = 0;
//	scanf("%d", &one_back_crime);
//	printf("%d %c", one_back_crime, one_back_crime);
//	return 0;
//}


/*
 * arr【5】，n
 * 1.取得每位数（递归）
 *   fuc（n）
 *   arr[i]= n%10；
 *   i++
 *   fun（n/10）
 * 2.(out=arr【2】*10+arr【1】)*10...
 */

//void get_number(int* num, int one_back_crime)
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		*num = one_back_crime % 10;
//		num++;
//		one_back_crime /= 10;
//	}
//
//}
//
//int main(void)
//{
//	int num[5] = { 0 };
//	int one_back_crime = 0;
//	scanf("%d", &one_back_crime);
//	get_number(num, one_back_crime);
//	printf("%d\n", (((num[2] * 10 + num[3]) * 10 + num[4]) * 10 + num[0]) * 10 + num[1]);
//	return 0;
//}
// 完全错误：用getchar！！！
//123
//int main(void)
//{
//	char one_back_crime[5] = { 0 };
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%c", one_back_crime + i);
//	}
//	printf("%c%c%c%c%c", one_back_crime[2], one_back_crime[1], one_back_crime[0], one_back_crime[4], one_back_crime[3]);
//	return 0;
//}

//int main(void)
//{
//	const double G = 6.674E-11;
//	double f = 0;
//	double M = 77.15;
//	double R = 0;
//	double m = 0;
//	scanf("%lf %lf", &m, &R);
//	f = G * M * m * 1.0 / pow(R, 2);
//	printf("%.3e", f);
//	return 0;
//}


//int main(void)
//{
//	int year, month, day;
//	double a, y, m;
//	int JDA = 0;
//	scanf("%d%d%d", &year, &month, &day);
//	a = floor((14 - month) * 1.0 / 12);
//	y = year + 4800 - a;
//	m = month + 12 * a - 3;
//	JDA = day + floor((153 * m + 2) * 1.0 / 5)+365*y+ floor(y*1.0/4)- floor(y*1.0/100)+ floor(y*1.0/400)-32045;
//	printf("%d",JDA);
//	return 0;
//}

//int main(void)
//{
//	int p, q;
//	double x1;
//	scanf("%d%d", &p, &q);
//	double mid = sqrt(pow(q * 1.0 / 2, 2) + pow(p * 1.0 / 3, 3));
//	x1 = cbrt(-q * 1.0 / 2 + mid) + cbrt(-q * 1.0 / 2 - mid);
//	printf("%.3f", x1);
//	return 0;
//
//}
//
//int main()
//{
//	int a = -3;
//	printf("%f", pow(a, 1.0 / 3));
//	return 0;
//}