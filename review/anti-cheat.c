//
// Created by xiexu on 2023/2/18.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct person
{
	int max_hp;
	int atk;
	int def;
	int speed;
	int prev_x;
	int prev_y;
	bool is_first_time;
	bool is_cheat;
	int prev_time;
} Person;
Person host = { 0 };
Person guest = { 0 };

void Judge(Person* input);

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	host.is_first_time = true;
	host.is_cheat = false;

	guest.is_first_time = true;
	guest.is_cheat = false;

	for (int i = 0; i < n; i++)
	{
		char input_array[30] = { 0 };
		scanf("%s", input_array);

		if (!strcmp(input_array, "Send"))
			Judge(&host);
		else
			Judge(&guest);

	}

	if (host.is_cheat && guest.is_cheat)
		printf("This game is terrible!\n");
	else if (host.is_cheat)
		printf("Host Cheated!\n");
	else if (guest.is_cheat)
		printf("Guest Cheated!\n");
	else
		printf("Good Game!\n");

	return 0;
}

void Judge(Person* input)
{
	int time = 0;
	int hp = 0;
	int atk = 0;
	int def = 0;
	int speed = 0;
	int x = 0;
	int y = 0;

	scanf("%*s%*s%d%*s%d%*s%d%*s%d%*s%d%*s%*s%d%*s%*s%d", &time, &hp, &atk, &def, &speed, &x, &y);

	if ((*input).is_first_time)
	{
		(*input).speed = speed;
		(*input).atk = atk;
		(*input).def = def;
		(*input).max_hp = hp;
		if (hp < 0)
		{
			(*input).is_cheat = true;
			return;
		}
		(*input).prev_x = x;
		(*input).prev_y = y;
		(*input).is_first_time = false;
		(*input).prev_time = time;
	}
	else
	{
		if ((*input).speed != speed || (*input).atk != atk || (*input).def != def
			|| hp < 0 || hp > (*input).max_hp || time <= (*input).prev_time)
		{
			(*input).is_cheat = true;
			return;
		}
		int delta_x = (*input).prev_x - x;
		delta_x = (delta_x > 0) ? delta_x : -delta_x;
		int delta_y = (*input).prev_y - y;
		delta_y = (delta_y > 0) ? delta_y : -delta_y;

		if ((delta_y + delta_x) > (*input).speed * (time - (*input).prev_time))
		{
			(*input).is_cheat = true;
			return;
		}
		(*input).prev_time = time;
		(*input).prev_x = x;
		(*input).prev_y = y;
	}

}
