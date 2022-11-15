//
// Created by xiexu on 2022/11/4.
//



#include <stdio.h>

int one_back_crime[100001] = { 0 };

int find_boss_crime(int sequence);

int main(void)
{
	int num_of_crime = 0;
	scanf("%d", &num_of_crime);

	for (int i = 1; i <= num_of_crime; i++)
	{
		scanf("%d", one_back_crime + i);
	}

	for (int i = 1; i <= num_of_crime; i++)
	{
		printf("%d ", find_boss_crime(i));
	}

	return 0;
}

int find_boss_crime(int sequence)
{
	if (sequence == one_back_crime[sequence])
		return sequence;
	else
		find_boss_crime(one_back_crime[sequence]);
}
