//
// Created by xiexu on 2022/11/7.
//

/*

3 2 1
ZYY 0 268 9
TXY 0 261 9
CQ 1 148 8

3 2 4
ZYY 1
TXY 0
CQ 1

2^8 = 256 ==> 1

1: --(left)
0: ++(right)f

 */



#include <stdio.h>
#include <math.h>

int highest_bit[1000009] = { 0 };
int facing_direction_array[1000009] = { 0 };

int main(void)
{
	int num_of_toy = 0;
	int bit_of_numbers = 0;
	int the_toy_CQ_face = 0;
	scanf("%d%d%d\n", &num_of_toy, &bit_of_numbers, &the_toy_CQ_face);
	the_toy_CQ_face--;
	the_toy_CQ_face %= num_of_toy;
	//看题：facing-numbers可能比玩具数量多。
	scanf(" ");

	for (int i = 0; i < num_of_toy; i++)
	{
		char tmp_input = 0;
		int aggregate_ascii = 0;
		while (tmp_input != ' ')
		{
			tmp_input = (char)getchar();
			if (tmp_input != ' ')
			{
				aggregate_ascii += tmp_input;
			}
		}
		scanf("%d", facing_direction_array + i);
		getchar();  // remove '\n'

		int number_bit = 0;
		for (number_bit = 0; aggregate_ascii != 0; aggregate_ascii >>= 1, number_bit++);
		highest_bit[i] = number_bit;
	}

	//find numbers
	//这种循环的方法很常用
	for (int i = 0; i < bit_of_numbers; i++)
	{
		printf("%d ", highest_bit[the_toy_CQ_face]);
		int the_range_CQ_pass = (int)pow(2, highest_bit[the_toy_CQ_face] - 1);
		the_range_CQ_pass %= num_of_toy;
		if (facing_direction_array[the_toy_CQ_face])
		{
			the_range_CQ_pass = num_of_toy - the_range_CQ_pass;
		}
		the_toy_CQ_face += the_range_CQ_pass;
		the_toy_CQ_face %= num_of_toy;
	}

	return 0;
}

