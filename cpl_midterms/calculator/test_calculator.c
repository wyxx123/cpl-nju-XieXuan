#include <stdio.h>
#include <string.h>
#include <setjmp.h>

jmp_buf buf;

// TOKEN 的类型
enum TOKEN_TYPE
{
	VAR, NUM, PLUS, MINUS, MULTIPLY, DIVIDE, LEFT_BRACKET, RIGHT_BRACKET, ASSIGN, NEG
};

enum VAL_TYPE
{
	LL, DBL
};

struct Value
{
	enum VAL_TYPE val_type;

	long long ll;
	double dbl;
};

// TOKEN
struct TOKEN
{
	enum TOKEN_TYPE type;

	struct Value val;
	char varname[300];
};

// 变量
struct VARIABLE
{
	char varname[300];
	struct Value val;
};

char input[1000000];
int len;

struct TOKEN token[100000];
int t_len;

struct VARIABLE variable[100000];
int var_len;

int is_assign;

int parse(int l, int r)
{
	for (int i = l; i <= r; i++)
	{

		if (input[i] == '(')
		{
			token[t_len++].type = LEFT_BRACKET;
		}
		else if (input[i] == ')')
		{
			token[t_len++].type = RIGHT_BRACKET;
		}
		else if (input[i] == '+')
		{
			token[t_len++].type = PLUS;
		}
		else if (input[i] == '-')
		{

			if (t_len == 0 || token[t_len - 1].type >= PLUS && token[t_len - 1].type <= DIVIDE
				|| token[t_len - 1].type == NEG || token[t_len - 1].type == ASSIGN
				|| token[t_len - 1].type == LEFT_BRACKET)
			{
				token[t_len++].type = NEG;
				continue;
			}

			token[t_len++].type = MINUS;
		}
		else if (input[i] == '*')
		{
			token[t_len++].type = MULTIPLY;
		}
		else if (input[i] == '/')
		{
			token[t_len++].type = DIVIDE;
		}
		else if (input[i] == ' ')
		{
			continue;
		}
		else if (input[i] == '=')
		{
			token[t_len++].type = ASSIGN;
			is_assign = 1;
		}
		else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')
		{
			char num_temp[1000] = { '\0' };
			int num_len = 0;
			int is_double = 0;

			struct Value temp_val;

			while (input[i] >= '0' && input[i] <= '9' || input[i] == '.')
			{
				if (input[i] == '.') is_double = 1;
			}
		}
	}
}