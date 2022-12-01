//
// Created by xiexu on 2022/11/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN_OF_RULE 135
#define MAX_LEN_PER_COMMENT 1100

int main(void)
{
	char* array_of_double_rules = malloc(MAX_LEN_OF_RULE * sizeof(char));
	char* array_of_single_rules = malloc(MAX_LEN_OF_RULE * sizeof(char));
	char** pointer_of_answer_array = malloc(MAX_LEN_PER_COMMENT * sizeof(char*));

	int num_of_double_rules = 0;
	int num_of_single_rules = 0;

	memset(array_of_double_rules, 0, MAX_LEN_OF_RULE * sizeof(char));
	memset(array_of_single_rules, 0, MAX_LEN_OF_RULE * sizeof(char));

	char* tmp_input_rule = malloc(MAX_LEN_OF_RULE * sizeof(char));

	scanf("%135s", tmp_input_rule);
	int len_of_tmp_input = (int)strlen(tmp_input_rule);
	for (int i = 0; i < len_of_tmp_input; i++)
	{
		if (*(tmp_input_rule + i) == ':')
			continue;

		if (*(tmp_input_rule + i + 1) == ':')
			*(array_of_double_rules + (num_of_double_rules++)) = *(tmp_input_rule + i);
		else
			*(array_of_single_rules + (num_of_single_rules++)) = *(tmp_input_rule + i);
	}

	//remember to clear this array.
	char* tmp_input_comment = malloc(MAX_LEN_PER_COMMENT * sizeof(char));

	//to input and judge rules.
	bool is_input_end = false;
	int num_of_answer = 0;
	char wrong_option = 0;
	int wrong_station = 0;
	bool is_value_set = false;
	for (int i = 0; i < MAX_LEN_PER_COMMENT; i++)
	{
		char* answer_each_term = malloc(MAX_LEN_PER_COMMENT);
		memset(answer_each_term, 0, MAX_LEN_PER_COMMENT);
		*(pointer_of_answer_array + i) = answer_each_term;
		if (num_of_answer == 0)
		{
			scanf("%1100s", *pointer_of_answer_array);
			num_of_answer++;
		}
		else
		{
			do
			{
				if (scanf("%1100s", tmp_input_comment) == EOF)
					is_input_end = true;

				is_value_set = false;
				if (*tmp_input_comment == '-' && strlen(tmp_input_comment) == 2
					&& is_input_end == false) //? if there is more than ...
				{
					for (int j = 0; j < MAX_LEN_OF_RULE; j++)
					{
						if (*(array_of_single_rules + j) == *(tmp_input_comment + 1))
						{
							strncpy(*(pointer_of_answer_array + num_of_answer), tmp_input_comment + 1, 2); //?
							num_of_answer++;
							is_value_set = true;
							break;
						}
					}
					if (is_value_set)
						break;

					char option = *(tmp_input_comment + 1);
					for (int j = 0; j < MAX_LEN_PER_COMMENT; j++)
					{
						if (*(array_of_double_rules + j) == *(tmp_input_comment + 1))
						{
							if (scanf("%1100s", tmp_input_comment) == EOF)
							{
								//lack argument.
								wrong_station = -1; // option requires an argument
								wrong_option = option;
								break;
							}

							//true
							*(*(pointer_of_answer_array + num_of_answer)) = option;
							*(*(pointer_of_answer_array + num_of_answer) + 1) = '=';
							strncpy(2 + *(pointer_of_answer_array + num_of_answer),
								tmp_input_comment, strlen(tmp_input_comment) + 1);
							num_of_answer++;
							is_value_set = true;
							break;
						}
					}
					if (is_value_set || wrong_station != 0)
						break;

					wrong_station = -2;//invalid option
					wrong_option = option;
				}

			} while (is_input_end == false && wrong_station == 0);
		}

		if (is_input_end == true || wrong_station != 0)
			break;
	}

	//print answer:
	switch (wrong_station)
	{
	case -1:
		printf("%s: option requires an argument -- '%c'\n", *pointer_of_answer_array, wrong_option);
		break;
	case -2:
		printf("%s: invalid option -- '%c'\n", *pointer_of_answer_array, wrong_option);
		break;
	default:
		for (int i = 0; i < num_of_answer; i++)
		{
			printf("%s\n", *(pointer_of_answer_array + i));
		}
		break;
	}

	//mount: invalid option -- 'k'
	//mount: option requires an argument -- 't'

	for (int i = 0; i < num_of_answer; i++)
	{
		free(*(pointer_of_answer_array + i));
	}
	free(pointer_of_answer_array);
	free(tmp_input_comment);
	free(tmp_input_rule);
	free(array_of_double_rules);
	free(array_of_single_rules);
	return 0;
}
