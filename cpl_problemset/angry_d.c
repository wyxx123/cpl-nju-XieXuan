//
// Created by xiexu on 2022/11/2.
//




#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int num_of_staff = 0;
	int walking_ability = 0;
	int len_of_avenue = 0;

	int place_to_hide[10001] = { 0 };
	int input_of_place = 0;
	scanf("%d%d%d", &num_of_staff, &walking_ability, &len_of_avenue);
	for (int i = 0; i < num_of_staff; i++)
	{
		scanf("%d", &input_of_place);
		place_to_hide[input_of_place]++;
	}
	walking_ability++;//not quite understand that range = ability + 1

	int caught_staff_num = 0;
	for (int i = 1; i <= walking_ability; i++)
	{
		caught_staff_num += place_to_hide[i];
	}

	int max_number = caught_staff_num;
	int cumulating_staff_num = max_number;
	int starting_point = 1;
	bool have_been_newed = false;
	for (int i = 2; i <= (len_of_avenue - walking_ability) + 1; i++)
	{
		caught_staff_num = caught_staff_num - place_to_hide[i - 1]
			+ place_to_hide[walking_ability + (i - 1)];
		cumulating_staff_num += place_to_hide[walking_ability + (i - 1)];
		if (((caught_staff_num > max_number) || ((caught_staff_num == max_number) && (have_been_newed == false)))
			&& (place_to_hide[i] != 0)) // didn't consider (at first) `the first num must be the place where staff(s) hid`
		{
			max_number = caught_staff_num;
			starting_point = i;
			have_been_newed = true;
		}

		if ((cumulating_staff_num == num_of_staff) && (place_to_hide[i] != 0))
			break; // didn't consider (at first) `the first num must be the place where staff(s) hid`
	}

	printf("%d %d\n", starting_point, starting_point + walking_ability - 1);
	printf("%d\n", max_number);

	return 0;
}

//*********************************************
//turning point:
//5 1 3
//1
//2     standard output: 2 3 4(->2)
//2
//3
//3
//********************************************


//5 3 100
//4
//3
//3
//4
//7

//4 2 3
//1
//2
//3
//3

//1 1 2
//1

//2 1 1
//1
//1

//5 1 100
//3
//4
//6
//6
//8

//5 1 3
//1
//2
//2
//3
//3
