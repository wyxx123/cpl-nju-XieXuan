//
// Created by xiexu on 2022/11/29.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN_EACH_INPUT 4100

int num_of_tokens = 0;

enum type_of_word
{
	reversed_type,
	integer_type,
	float_type,
	operator_type,
	variable_type,
	new_line
};

enum type_of_word* array_of_answers = NULL;

bool JudgeFormat(const char* tmp_input, char** pointer_of_reversed_array, char** pointer_of_operator_array);

int main(void)
{
	array_of_answers = (enum type_of_word*)malloc(MAX_LEN_EACH_INPUT * sizeof(int));

	char** pointer_of_reversed_array = (char**)malloc(16 * sizeof(char*));
	*(pointer_of_reversed_array + 0) = "const";
	*(pointer_of_reversed_array + 1) = "int";
	*(pointer_of_reversed_array + 2) = "float";
	*(pointer_of_reversed_array + 3) = "double";
	*(pointer_of_reversed_array + 4) = "long";
	*(pointer_of_reversed_array + 5) = "static";
	*(pointer_of_reversed_array + 6) = "void";
	*(pointer_of_reversed_array + 7) = "char";
	*(pointer_of_reversed_array + 8) = "extern";
	*(pointer_of_reversed_array + 9) = "return";
	*(pointer_of_reversed_array + 10) = "break";
	*(pointer_of_reversed_array + 11) = "enum";
	*(pointer_of_reversed_array + 12) = "struct";
	*(pointer_of_reversed_array + 13) = "typedef";
	*(pointer_of_reversed_array + 14) = "union";
	*(pointer_of_reversed_array + 15) = "goto";

	char** pointer_of_operator_array = (char**)malloc(11 * sizeof(char*));
	*(pointer_of_operator_array + 0) = "+";
	*(pointer_of_operator_array + 1) = "-";
	*(pointer_of_operator_array + 2) = "*";
	*(pointer_of_operator_array + 3) = "/";
	*(pointer_of_operator_array + 4) = "=";
	*(pointer_of_operator_array + 5) = "==";
	*(pointer_of_operator_array + 6) = "!=";
	*(pointer_of_operator_array + 7) = ">=";
	*(pointer_of_operator_array + 8) = "<=";
	*(pointer_of_operator_array + 9) = ">";
	*(pointer_of_operator_array + 10) = "<";

	//judge
	char* tmp_input = malloc(MAX_LEN_EACH_INPUT * sizeof(char));
	bool is_format_right = true;
	while (scanf("%4099s", tmp_input) != EOF)
	{
		if (is_format_right == false)
			break;

		int len_of_token = (int)strlen(tmp_input);

		bool is_new_line = false;
		int sequence_of_ch = 0;
		for (sequence_of_ch = 0; sequence_of_ch < len_of_token; sequence_of_ch++)
		{
			if (*(tmp_input + sequence_of_ch) == ';')
			{
				is_new_line = true;
				break;
			}
		}

		if (is_new_line == true)
		{
			*(tmp_input + sequence_of_ch) = 0;
			if (sequence_of_ch != 0)
				is_format_right = JudgeFormat(tmp_input, pointer_of_reversed_array, pointer_of_operator_array);

			*(array_of_answers + num_of_tokens) = new_line;
			num_of_tokens++;

			if (is_format_right && sequence_of_ch != len_of_token - 1)
			{
				is_format_right =
					JudgeFormat(tmp_input + sequence_of_ch + 1, pointer_of_reversed_array, pointer_of_operator_array);
			}
		}
		else
			is_format_right = JudgeFormat(tmp_input, pointer_of_reversed_array, pointer_of_operator_array);

		memset(tmp_input, 0, MAX_LEN_EACH_INPUT);
	}

	//print
	if (is_format_right == true)
	{
		bool is_first_word = true;
		for (int i = 0; i < num_of_tokens; i++)
		{
			if (is_first_word == false && *(array_of_answers + i) != new_line)
			{
				printf(" ");
			}

			if (is_first_word)
				is_first_word = false;

			switch (*(array_of_answers + i))
			{
			case reversed_type:
				printf("reserved");
				break;
			case integer_type:
				printf("integer");
				break;
			case float_type:
				printf("float");
				break;
			case operator_type:
				printf("operator");
				break;
			case variable_type:
				printf("variable");
				break;
			case new_line:
				printf("\n");
				is_first_word = true;
				break;
			default:
				return -1;
			}
		}
	}
	else
		printf("Compile Error\n");


	//free
	free(array_of_answers);
	free(pointer_of_reversed_array);
	free(pointer_of_operator_array);
	free(tmp_input);
	return 0;
}

/**
 *
 * @param tmp_input
 * @param pointer_of_reversed_array
 * @param pointer_of_operator_array
 * @return true:correct format,false:wrong
 */
bool JudgeFormat(const char* tmp_input, char** pointer_of_reversed_array, char** pointer_of_operator_array)
{
	for (int i = 0; i < 16; i++)
	{
		if (strncmp(tmp_input, *(pointer_of_reversed_array + i), MAX_LEN_EACH_INPUT) == 0)
		{
			*(array_of_answers + num_of_tokens) = reversed_type;
			num_of_tokens++;
			return true;
		}
	}

	for (int i = 0; i < 11; i++)
	{
		if (strncmp(tmp_input, *(pointer_of_operator_array + i), MAX_LEN_EACH_INPUT) == 0)
		{
			*(array_of_answers + num_of_tokens) = operator_type;
			num_of_tokens++;
			return true;
		}
	}

	char first_ch = *tmp_input;
	int len_of_token = (int)strlen(tmp_input);
	if (first_ch == '.' || (first_ch <= '9' && first_ch >= '0'))
	{
		int count_of_point = 0;
		for (int i = 0; i < len_of_token; i++)
		{
			char tmp_ch = *(tmp_input + i);
			if (tmp_ch != '.' && (tmp_ch > '9' || tmp_ch < '0'))
			{
				return false;
			}

			if (tmp_ch == '.')
				count_of_point++;
		}

		switch (count_of_point)
		{
		case 0:
			if (len_of_token != 1 && first_ch == '0')
				return false;
			else
			{
				*(array_of_answers + num_of_tokens) = integer_type;
				num_of_tokens++;
				return true;
			}

		case 1:
			if (first_ch == '0' && *(tmp_input + 1) != '.')
				return false;
			else
			{
				*(array_of_answers + num_of_tokens) = float_type;
				num_of_tokens++;
				return true;
			}

		default:
			return false;
		}
	}
	else if ((first_ch >= 'a' && first_ch <= 'z') || (first_ch >= 'A' && first_ch <= 'Z') || first_ch == '_')
	{
		for (int i = 0; i < len_of_token; i++)
		{
			char tmp_ch = *(tmp_input + i);
			if ((tmp_ch < 'a' || tmp_ch > 'z') && (tmp_ch < 'A' || tmp_ch > 'Z') && tmp_ch != '_'
				&& (tmp_ch <= '9' && tmp_ch >= '0'))
				return false;
		}

		//true
		*(array_of_answers + num_of_tokens) = variable_type;
		num_of_tokens++;
		return true;
	}
	else
		return false;
}

