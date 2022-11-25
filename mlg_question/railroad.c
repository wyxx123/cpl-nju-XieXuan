//
// Created by xiexu on 2022/11/18.
//
#include <stdio.h>
//#include "data_maker.cpp"

int main(void)
{
	int stack_station_1[1000] = { 0 };
	int stack_station_2[1000] = { 0 };
//	int* bottom_1 = stack_station_1;
	int* top_1 = stack_station_1;
//	int* bottom_2 = stack_station_2;
	int* top_2 = stack_station_2;
	int position_of_car[1001] = { 0 };

	int num_of_car = 0;
	scanf("%d", &num_of_car);

	for (int i = 1; i <= num_of_car; i++)
	{
		while (position_of_car[i] == 0)
		{
			int input = 0;
			scanf("%d", &input);
			position_of_car[input] = 1;
			*top_1 = input;
			top_1++;

			printf("1\n");
		}

		if (position_of_car[i] == 1)
		{
			while (*(top_1 - 1) != i)
			{
				top_1--;
				*top_2 = *top_1;
				position_of_car[*top_1] = 2;
				top_2++;
				printf("12\n");
			}

			//have found 1
			top_1--;
			printf("-1\n");
			position_of_car[i] = -1;
		}

		if (position_of_car[i] == 2)
		{
			while (*(top_2 - 1) != i)
			{
				top_2--;
				*top_1 = *top_2;
				position_of_car[*top_2] = 1;
				top_1++;
				printf("21\n");
			}

			//have found 2
			top_2--;
			printf("-2\n");
			position_of_car[i] = -1;
		}
	}

	return 0;
}