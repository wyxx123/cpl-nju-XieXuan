//
// Created by xiexu on 2022/10/28.
//

/*
 * difficulty ++(--)
 *
 *
 * int JudgeRadix(``)
 *   for(int i= 2 <=40)
 *   if(IsRadixOver(i,p) || ) continue;
 *   if(IsRadix(i,``)) return i;
 * return 0;
 *
 * bool IsRadixOver(``)
 * if(i > num/10 && i > num % 10)
 *   return true
 * return false
 *
 *
 * bool IsRadix``
 * int sub_p = ChangeTenthRadix(p,i)
 * ``
 * ``
 * if(sp*sq==sr)
 *   return true;
 * return false;
 *
 * int ChangeTenthRadix(num, radix)
 *
 *  if(num/10)
 *   return  radix*(num/10) + num%10
 *  else
 *    return num
 *
 *
 * scanf p q r
 *
 * printf(, JudgeRadix(i,p,q,r))
 *
 *
 */

#include <stdio.h>
#include <stdbool.h>

int JudgeRadix(int p, int q, int r);
bool IsRadix(int i, int p, int q, int r);
int ChangeTenthRadix(int num, int radix);
bool IsRadixLess(int radix, int num);

int main(void)
{
	int p = 0;
	int q = 0;
	int r = 0;
	scanf("%d%d%d", &p, &q, &r);

	printf("%d\n", JudgeRadix(p, q, r));

	return 0;
}

int JudgeRadix(int p, int q, int r)
{
	for (int i = 2; i <= 40; i++)
	{
		if (IsRadixLess(i, p) || IsRadixLess(i, q) || IsRadixLess(i, r))
			continue;
		if (IsRadix(i, p, q, r))
			return i;
	}
	return 0;
}

bool IsRadixLess(int radix, int num)
{
	if ((num % 10 < radix) && (num / 10 < radix))
		return false;

	return true;
}

bool IsRadix(int i, int p, int q, int r)
{
	int sub_p = ChangeTenthRadix(p, i);
	int sub_q = ChangeTenthRadix(q, i);
	int sub_r = ChangeTenthRadix(r, i);

	if (sub_p * sub_q == sub_r)
		return true;

	return false;
}

int ChangeTenthRadix(int num, int radix)
{
	if (num / 10)
		return radix * (num / 10) + num % 10;

	return num;
}
