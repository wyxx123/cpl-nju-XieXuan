//
// Created by xiexu on 2022/12/9.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 25
#define MAX_TEAM 1009
#define PEOPLE_EACH_TEAM 11

typedef struct people
{
	char people_name[MAX_NAME];
	int people_attack;
	int people_defend;
	int people_organize;
} People;

typedef struct team
{
	char team_name[MAX_NAME];
	People peoples[PEOPLE_EACH_TEAM];
	double group_attack;
	double group_defend;
	double group_organize;
} Team;

Team teams[MAX_TEAM] = { 0 };

int CompareAttack(const void* left, const void* right);
int CompareDefend(const void* left, const void* right);
int CompareOrganize(const void* left, const void* right);

int main(void)
{
	int num_of_team = 0;
	scanf("%d", &num_of_team);

	for (int i = 0; i < num_of_team; i++)
	{
		scanf("%25s", teams[i].team_name);

		for (int j = 0; j < PEOPLE_EACH_TEAM; j++)
		{
			scanf("%s%d%d%d", teams[i].peoples[j].people_name,
				&teams[i].peoples[j].people_attack,
				&teams[i].peoples[j].people_defend,
				&teams[i].peoples[j].people_organize);
		}

		//attack
		int sum = 0;
		for (int j = 0; j < PEOPLE_EACH_TEAM; j++)
		{
			sum += teams[i].peoples[j].people_attack;
		}
		teams[i].group_attack = sum * 1.0 / PEOPLE_EACH_TEAM;

		//defend
		sum = 0;
		for (int j = 0; j < PEOPLE_EACH_TEAM; j++)
		{
			sum += teams[i].peoples[j].people_defend;
		}
		teams[i].group_defend = sum * 1.0 / PEOPLE_EACH_TEAM;

		//organize
		sum = 0;
		for (int j = 0; j < PEOPLE_EACH_TEAM; j++)
		{
			sum += teams[i].peoples[j].people_organize;
		}
		teams[i].group_organize = sum * 1.0 / PEOPLE_EACH_TEAM;
	}

	qsort(teams, num_of_team, sizeof *teams, CompareAttack);
	for (int i = 0; i < num_of_team; i++)
	{
		printf("%s ", teams[i].team_name);
	}
	printf("\n");

	qsort(teams, num_of_team, sizeof *teams, CompareDefend);
	for (int i = 0; i < num_of_team; i++)
	{
		printf("%s ", teams[i].team_name);
	}
	printf("\n");

	qsort(teams, num_of_team, sizeof *teams, CompareOrganize);
	for (int i = 0; i < num_of_team; i++)
	{
		printf("%s ", teams[i].team_name);
	}
	printf("\n");

	return 0;
}

int CompareAttack(const void* left, const void* right)
{
	Team left_team = *(const Team*)left;
	Team right_team = *(const Team*)right;

	if (left_team.group_attack == right_team.group_attack)
		return 0;

	if (left_team.group_attack > right_team.group_attack)
		return -1;

	return 1;
}

int CompareDefend(const void* left, const void* right)
{
	Team left_team = *(const Team*)left;
	Team right_team = *(const Team*)right;

	if (left_team.group_defend == right_team.group_defend)
		return 0;

	if (left_team.group_defend > right_team.group_defend)
		return -1;

	return 1;
}

int CompareOrganize(const void* left, const void* right)
{
	Team left_team = *(const Team*)left;
	Team right_team = *(const Team*)right;

	if (left_team.group_organize == right_team.group_organize)
		return 0;

	if (left_team.group_organize > right_team.group_organize)
		return -1;

	return 1;
}
