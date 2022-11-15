//
// Created by xiexu on 2022/11/3.
//


#include <stdio.h>
#include <stdlib.h>

//void my_qsort_small_to_big(int* base, int size);
int compare_int(const void* num1, const void* num2)
{
	return *((const int*)num1) - *((const int*)num2);
}

int main(void)
{
	int num_of_skills = 0;
	int num_of_companion = 0;
	int maximum_of_skills_per_day = 0;

	int damage_of_skills[10000] = { 0 };
	scanf("%d%d%d", &num_of_skills, &num_of_companion, &maximum_of_skills_per_day);
	for (int i = 0; i < num_of_skills; i++)
	{
		int tmp_input = 0;
		int type = 0;
		scanf("%d%d", &tmp_input, &type);

		damage_of_skills[i] = (type == 0) ? tmp_input : (tmp_input * (1 + num_of_companion));
	}

	qsort(damage_of_skills, num_of_skills, 4, compare_int);

	int cumulated_damage = 0;
	for (int i = 0; i < maximum_of_skills_per_day; i++)
	{
		num_of_skills--;
		cumulated_damage += damage_of_skills[num_of_skills];
	}

	printf("%d\n", cumulated_damage);
}

//void my_qsort_small_to_big(int* base, int size)
//{
//
//}


