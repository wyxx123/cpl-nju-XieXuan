//
// Created by xiexu on 2022/10/22.
//

/*
 * 在课上我们学过了生命游戏的写法。现在我们实践一下，写一个降维版本的生命游戏（一维），规则如下

每个细胞有左右各3个，共6个相邻位置（如果在边缘处，则不考虑实际不存在的位置）
有两个物种 A B 相互竞争
若此轮某位置为空，相邻位置上有 [2, 4][2,4] 个生命为同类，没有异类，则下轮在此处生成一个同类生命
若此轮某位置存在生命
相邻位置上存在竞争物种，则在下轮消亡
相邻位置上存在 >=5 个同类物种，则因为拥挤而在下轮消亡
相邻位置上存在 <=1 个同类物种，则因为孤独而在下轮消亡
 *
 *
 *
 * scanf(n)
 *
 * char input [1006] = {0};
 *
 *   // for(int i = 0 ; < n)
 * scanf("%s", input);
 * int size = strlen(input)
 *
 * for()
 * //initialized next_char
 *
 * for(i = 0 ; < sizes)
 * // one round
 *
 * //int num_a = 0 , num_b = 0 ;
 * for(int j = -3; <= 3)
 *  if(j != 0)
 *   if() - num_a
 *   else - num_b
 *
 * //one run
 *
 * if(input[i] == '.')
 * if((num_a>1&&num_a<5)&&num_b == 0)
 *   next_char [i] = 'A'
 *   \\
 *   -->B
 *
 * else if(input[i] == 'A' &&(num_b != 0||(num_a <= 1&&num_a >=5)) )
 *  -->'.'
 *
 *
 * --> next_char
 *
 * char -- next_char  //strncpy
 *
 *
 *
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	char input[1006] = { 0 };
	scanf("%1000s", input + 3);
	int size = strlen(input + 3);
	char next_char[1006] = { 0 };

	strncpy(next_char + 3, input + 3, 1000);

	for (int t = 0; t < n; t++)
	{
		for (int i = 3; i < size + 3; i++)
		{
			//	memset(input,'.')
			int num_a = 0;
			int num_b = 0;
			for (int j = -3; j <= 3; j++)
			{
				if (j != 0)
				{
					if (input[i + j] == 'A')
					{
						num_a++;
					}

					if (input[i + j] == 'B')
					{
						num_b++;
					}
				}
			}

			if (input[i] == '.')
			{
				if (num_a > 1 && num_a < 5 && num_b == 0)
				{
					next_char[i] = 'A';
				}
				if (num_b > 1 && num_b < 5 && num_a == 0)
				{
					next_char[i] = 'B';
				}
			}

			// A/B --> .
			if (input[i] == 'A' && (num_b != 0 || (num_a <= 1 || num_a >= 5))
				|| input[i] == 'B' && (num_a != 0 || (num_b <= 1 || num_b >= 5)))
			{
				next_char[i] = '.';
			}
		}

		strncpy(input + 3, next_char + 3, size);
	}

	for (int i = 3; i < size + 3; i++)
	{
		printf("%c", input[i]);
	} //


	return 0;
}
