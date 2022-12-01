//
// Created by xiexu on 2022/11/26.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TOKENS_PER_LINE 6000
#define MAX_TOKEN_LEN 400
#define WRONG_RETURN (struct return_value){ .return_type = R_ERROR }
#define IMPOSABLE_TO_REACH assert(0);

//each type.
enum type
{
	ADD = 0,
	SUB = 1,
	MUL = 2,
	DEV = 3,
	DOUBLE = 4,
	INT = 5,
	L_BRACKET = 6,
	R_BRACKET = 7,
	VLR = 8,
	EQU = 9
};

enum op
{
	O_ADD = 0,
	O_SUB = 1,
	O_MUL = 2,
	O_DEV = 3
};

//each tokens
struct token
{
	enum type token_type;
	union
	{
		char name[MAX_TOKEN_LEN];
		int num_int;
		double num_double;
	} value;
};

//return value.
struct return_value
{
	enum
	{
		R_DOUBLE = 4,
		R_INT = 5,
		R_ERROR = 10
	} return_type;
	union
	{
		int int_val;
		double double_val;
	} val;
};

//variable.
struct variable
{
	enum type variable_type;
	char name[MAX_TOKEN_LEN];
	union
	{
		int int_value;
		double double_value;
	} value;
};

int count_of_variables = 0;

struct token tokens[MAX_TOKENS_PER_LINE] = { 0 };
struct variable variables[MAX_TOKENS_PER_LINE] = { 0 };
bool position_of_new_var_each_term[MAX_TOKENS_PER_LINE] = { 0 }; //judge new variable

void PrintResult(struct return_value return_value);
int JudgeWord(const char* input_tokens, const int* index_of_token);
struct return_value EvalAssign(int l, int r, int num_of_equ);
struct return_value Eval(int l, int r);
struct return_value MeetValue(struct return_value ret1, struct return_value ret2, enum op option);
bool CheckMinus(int l, int r);
int FindMainOp(int l, int r);
bool CheckBracket(int l, int r);
void cancel(int num_of_tokens);

int main(void)
{
	char input_ch = 0;

	//input:
	do
	{
		int num_of_equ = 0;
		int num_of_tokens = 0;
		int index_of_token = 0;
		bool is_word_right = true;
		memset(position_of_new_var_each_term, 0, MAX_TOKENS_PER_LINE * sizeof(bool));
		do
		{
			char input_tokens[MAX_TOKEN_LEN] = { 0 };
			if (scanf("%40s", input_tokens) == EOF)
				return 0;

			//词法分析及存入
			switch (JudgeWord(input_tokens, &index_of_token))
			{
			case 1:
				num_of_equ++;
				break;
			case 0:
				break;
			case -1:
				is_word_right = false;
				break;
			default:
				break;
			}

			num_of_tokens++;
			index_of_token++;
			input_ch = (char)getchar();
		} while (input_ch == ' ');

		//judge if new word is used.
		bool is_new_word_used = false;
		for (int i = 0; i < num_of_tokens; i++)
			if (position_of_new_var_each_term[i] == true && (i == num_of_tokens - 1
				|| tokens[i + 1].token_type != EQU))
			{
				is_new_word_used = true;
			}

		//if the word is right, then judge the sentence; else print err.
		if (is_word_right && is_new_word_used == false)
		{
			int l = 0;
			int r = num_of_tokens - 1;
			//语法分析-主体
			struct return_value return_value = EvalAssign(l, r, num_of_equ);

			//if the result is error, then cancel the variable.
			if (return_value.return_type == R_ERROR)
			{
				cancel(num_of_tokens);
			}

			PrintResult(return_value);
		}
		else
		{
			printf("Error\n");
			cancel(num_of_tokens);
		}

	} while (1);

}

void PrintResult(struct return_value return_value)
{
	if (return_value.return_type == R_ERROR)
		printf("Error\n");
	else if (return_value.return_type == R_INT)
		printf("%d\n", return_value.val.int_val);
	else
		printf("%f\n", return_value.val.double_val);
}

/**
 * to find the type and value of a token.
 * @param input_tokens the tokens
 * @return 1 if = is input
 */
int JudgeWord(const char* input_tokens, const int* index_of_token)
{
	char tmp_ch = *input_tokens;
	if (strlen(input_tokens) == 1)
	{
		//one char.
		switch (tmp_ch)
		{
		case '+':
			tokens[*index_of_token].token_type = ADD;
			return 0;
		case '-':
			tokens[*index_of_token].token_type = SUB;
			return 0;
		case '*':
			tokens[*index_of_token].token_type = MUL;
			return 0;
		case '/':
			tokens[*index_of_token].token_type = DEV;
			return 0;
		case '(':
			tokens[*index_of_token].token_type = L_BRACKET;
			return 0;
		case ')':
			tokens[*index_of_token].token_type = R_BRACKET;
			return 0;
		case '=':
			tokens[*index_of_token].token_type = EQU;
			return 1;
		default:
			if (tmp_ch == '_'
				|| (tmp_ch >= 'a' && tmp_ch <= 'z')
				|| (tmp_ch >= 'A' && tmp_ch <= 'Z')
				|| (tmp_ch >= '0' && tmp_ch <= '9'))
				break;
			return -1;
		}
	}

	//more than one char.(or one char variable).
	if ((tmp_ch >= 'a' && tmp_ch <= 'z')
		|| (tmp_ch >= 'A' && tmp_ch <= 'Z')
		|| tmp_ch == '_')//variable
	{

		for (int i = 1; i < strlen(input_tokens); i++)
		{
			char term_ch = input_tokens[i];
			if ((term_ch >= 'a' && term_ch <= 'z')
				|| (term_ch >= 'A' && term_ch <= 'Z')
				|| term_ch == '_'
				|| (term_ch >= '0' && term_ch <= '9'))
				continue;
			return -1;
		}

		//judge if the variable is used.
		bool is_variable_new = true;
		for (int i = 0; i < count_of_variables; i++)
		{
			if (strncmp(variables[i].name, input_tokens, MAX_TOKEN_LEN) == 0)
			{
				is_variable_new = false;
			}
		}


		//true
		if (is_variable_new == true)
		{
			//create a variable.
			tokens[*index_of_token].token_type = VLR;
			strncpy(variables[count_of_variables].name,
				strncpy(tokens[*index_of_token].value.name, input_tokens, MAX_TOKEN_LEN),
				MAX_TOKEN_LEN);

			//to switch to next variable
			count_of_variables++;

			//to say that this is a new variable.
			position_of_new_var_each_term[*index_of_token] = true;
		}
		else
		{
			for (int i = 0; i < MAX_TOKENS_PER_LINE; i++)
			{
				if (position_of_new_var_each_term[i] == true
					&& strncmp(tokens[i].value.name, input_tokens, MAX_TOKEN_LEN) == 0)
				{
					position_of_new_var_each_term[*index_of_token] = true;
				}
			}

			tokens[*index_of_token].token_type = VLR;
			strncpy(tokens[*index_of_token].value.name, input_tokens, MAX_TOKEN_LEN);
		}

		return 0;
	}

	//'-'
	int mark = 1;
	if (tmp_ch == '-')
	{
		input_tokens++;
		mark = -1;
		tmp_ch = *input_tokens;
	}

	if (tmp_ch >= '0' && tmp_ch <= '9')
	{
		for (int i = 1; i < strlen(input_tokens); i++)
		{
			char term_ch = input_tokens[i];
			if ((term_ch >= '0' && term_ch <= '9') || term_ch == '.')
				continue;
			return -1;
		}

		//to calculate number of .
		int num_of_point = 0;
		int position_of_point = 0;
		for (int i = 0; input_tokens[i] != '\0'; i++)
		{
			if (input_tokens[i] == '.')
			{
				num_of_point++;
				position_of_point = i;
			}
		}

		//int
		if (num_of_point == 0)
		{
			if (tmp_ch == '0' && strlen(input_tokens) != 1)
				return -1;

			tokens[*index_of_token].token_type = INT;
			tokens[*index_of_token].value.num_int = atoi(input_tokens) * mark;//not perfect...
			return 0;
		}

		//double
		if (num_of_point == 1)
		{
			//to judge the position of '.'
			if (position_of_point == 0 || position_of_point == strlen(input_tokens) - 1)
				return -1;

			if (tmp_ch == '0' && input_tokens[1] != '.')
				return -1;

			tokens[*index_of_token].token_type = DOUBLE;
			tokens[*index_of_token].value.num_double = atof(input_tokens) * mark; //not perfect...
			return 0;
		}
	}

	return -1;
}

struct return_value EvalAssign(int l, int r, int num_of_equ)
{
	if (num_of_equ == 0)
		return Eval(l, r);

	else if ((r > l + 1) && tokens[l].token_type == VLR
		&& tokens[l + 1].token_type == EQU)
	{
		struct return_value tmp_return = EvalAssign(l + 2, r, num_of_equ - 1);

		//find which variable.
		int i = 0;
		for (i = 0; i < count_of_variables; i++)
		{
			if (strncmp(variables[i].name, tokens[l].value.name, MAX_TOKEN_LEN) == 0)
				break;
		}

		//to update variable.
		if (tmp_return.return_type != R_ERROR)
			variables[i].variable_type = tmp_return.return_type;

		if (tmp_return.return_type == INT)
			variables[i].value.int_value = tmp_return.val.int_val;
		else if (tmp_return.return_type == DOUBLE)
			variables[i].value.double_value = tmp_return.val.double_val;

		//return.
		return tmp_return;
	}

	return WRONG_RETURN;
}

struct return_value Eval(int l, int r)
{
	if (l > r)
		return WRONG_RETURN;
	else if (l == r)
	{
		//judge if the token is legal.
		if (tokens[l].token_type != VLR && tokens[l].token_type != INT && tokens[l].token_type != DOUBLE)
			return WRONG_RETURN;

		//if legal...
		struct return_value tmp_return = { .return_type = tokens[l].token_type };
		if (tokens[l].token_type == INT)
			tmp_return.val.int_val = tokens[l].value.num_int;
		else if (tokens[l].token_type == DOUBLE)
			tmp_return.val.double_val = tokens[l].value.num_double;
		else
		{
			for (int i = 0; i < count_of_variables; i++)
			{
				if (strncmp(variables[i].name, tokens[l].value.name, MAX_TOKEN_LEN) == 0)
				{
					if (variables[i].variable_type == INT)
					{
						tmp_return.val.int_val = variables[i].value.int_value;
						tmp_return.return_type = INT;
						break;
					}
					if (variables[i].variable_type == DOUBLE)
					{
						tmp_return.val.double_val = variables[i].value.double_value;
						tmp_return.return_type = DOUBLE;
						break;
					}
				}
			}
		}
		return tmp_return;
	}
	else if (CheckBracket(l, r) == true)
	{
		return Eval(l + 1, r - 1);
	}
	else if (CheckMinus(l, r) == true)
	{
		return MeetValue(Eval(l + 1, r),
			(struct return_value){ .return_type = R_INT, .val.int_val = -1 },
			O_MUL);
	}
	else
	{
		int position_of_main_op = FindMainOp(l, r);

		//judge
		if (position_of_main_op == -1)
			return WRONG_RETURN;

			//true
		else
		{
			return MeetValue(Eval(l, position_of_main_op - 1),
				Eval(position_of_main_op + 1, r),
				(enum op)(tokens[position_of_main_op].token_type));
		}
	}
}

struct return_value MeetValue(struct return_value ret1, struct return_value ret2, enum op option)
{
	//return err for some.
	if (ret1.return_type == R_ERROR || ret2.return_type == R_ERROR)
		return WRONG_RETURN;

	bool is_int = false;
	//promote type int to double.
	double num1 = 0;
	double num2 = 0;
	if (ret1.return_type != ret2.return_type)
	{
		if (ret1.return_type == R_INT)
		{
			num1 = (double)ret1.val.int_val;
			num2 = ret2.val.double_val;
		}
		else
		{
			num1 = ret1.val.double_val;
			num2 = (double)ret2.val.int_val;
		}
	}
	else if (ret1.return_type == R_INT)
	{
		num1 = ret1.val.int_val;
		num2 = ret2.val.int_val;
		is_int = true;
	}
	else
	{
		num1 = ret1.val.double_val;
		num2 = ret2.val.double_val;
	}

	//to calculate.
	struct return_value tmp_ret = { .return_type = is_int ? R_INT : R_DOUBLE };
	double tmp_result = 0;
	switch (option)
	{
	case O_ADD:
		tmp_result = num1 + num2;
		break;
	case O_SUB:
		tmp_result = num1 - num2;
		break;
	case O_MUL:
		tmp_result = num1 * num2;
		break;
	case O_DEV:
		tmp_result = num1 / num2;
		break;
	default:
		IMPOSABLE_TO_REACH
	}
	if (is_int)
		tmp_ret.val.int_val = (int)tmp_result;
	else
		tmp_ret.val.double_val = tmp_result;

	return tmp_ret;
}

bool CheckMinus(int l, int r)
{
	//l -> the first token not '-'
	for (; tokens[l].token_type == SUB; l++);

	if (l > r)
		return false;
	if (l == r
		&& (tokens[l].token_type == INT
			|| tokens[l].token_type == DOUBLE
			|| tokens[l].token_type == VLR))
		return true;
	if (CheckBracket(l, r) == true)
		return true;

	return false;
}

int FindMainOp(int l, int r)
{
	int num_state_of_right_bracket = 0;
	int max_position_of_mul_dev = -1;
	int max_position_of_add_sub = -1;
	for (; l <= r; r--)
	{
		enum type type_of_r = tokens[r].token_type;
		if (type_of_r == R_BRACKET)
			num_state_of_right_bracket++;
		if (type_of_r == L_BRACKET)
			num_state_of_right_bracket--;

		//place able to find main operation.
		if (num_state_of_right_bracket == 0)
		{
			if (type_of_r == INT || type_of_r == DOUBLE || type_of_r == VLR)
				continue;
			if (max_position_of_mul_dev == -1 && (type_of_r == MUL || type_of_r == DEV))
				max_position_of_mul_dev = r;
			if (type_of_r == ADD)
			{
				max_position_of_add_sub = r;
				break;
			}
			if (type_of_r == SUB && l != r)
			{
				enum type type_of_pre_r = tokens[r - 1].token_type;
				if (type_of_pre_r == ADD || type_of_pre_r == SUB
					|| type_of_pre_r == MUL || type_of_pre_r == DEV)
				{
					continue;
				}
				else
				{
					max_position_of_add_sub = r;
					break;
				}
			}
		}
	}

	//return :
	if (max_position_of_add_sub != -1)
		return max_position_of_add_sub;
	return max_position_of_mul_dev;
}

bool CheckBracket(int l, int r)
{
	if (tokens[l].token_type != L_BRACKET || tokens[r].token_type != R_BRACKET)
		return false;

	int number_state_of_r_bracket = 1;
	for (r -= 1; r >= l; r--)
	{
		if (tokens[r].token_type == R_BRACKET)
			number_state_of_r_bracket++;
		if (tokens[r].token_type == L_BRACKET)
			number_state_of_r_bracket--;

		if (number_state_of_r_bracket == 0)
			break;
	}

	return (r == l);
}

void cancel(int num_of_tokens)
{
	for (int i = 0; i < num_of_tokens; i++)
	{
		if (position_of_new_var_each_term[i] == true)
		{
			for (int j = count_of_variables - 1; j >= 0; j--)
			{
				if (strncmp(tokens[i].value.name, variables[j].name, MAX_TOKEN_LEN) == 0)
					memset(variables[j].name, 0, MAX_TOKEN_LEN);
			}
		}
	}
}



//1 - - - - 1
//1 - 1
//1 + ( - - - 1 )


