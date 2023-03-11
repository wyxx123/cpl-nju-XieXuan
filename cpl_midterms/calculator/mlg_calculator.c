//
// Created by xiexu on 2022/12/8.
//

//这个是mlg的代码~ 写的真好！ヾ(≧▽≦*)oヾ(≧▽≦*)oヾ(≧▽≦*)o

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define debug puts("Lg")
#define N 100000
#define mod 19260817
#define dl double
typedef struct token
{
	int type;
	char str[32];
	int iVal;
	double fVal;
	char op;
} Token;

int cnt;
int len[N];
Token tokens[N];
int bel[20000];
#define type(p) tokens[p].type
#define val(p) tokens[p].val

bool isoperator(char c)
{
	return c == '*' || c == '/' || c == '+' || c == '-' || c == '=' || c == '(' || c == ')';
}
bool iscalc(char c)
{
	return c == '*' || c == '/' || c == '+' || c == '-' || c == '=';
}
bool isdigit(char c)
{
	return c >= '0' && c <= '9';
}
bool issmall(char c)
{
	return 'a' <= c && c <= 'z';
}
bool isbig(char c)
{
	return 'A' <= c && c <= 'Z';
}

//哈希 用以判断两字符串是否相同
int hash(char* st, char* ed)
{
	char* now = st;
	int rem = 0;
	while (now < ed && *now != '\0')
	{
		rem *= 63;
		rem += *now;
		rem %= mod;
		++now;
	}
	return rem;
}

int word_analysis(int p)
{
	//operator
	if (len[p] == 1 && isoperator(tokens[p].str[0]))
	{
		tokens[p].op = tokens[p].str[0];
		return 1;
	}

	//variable
	if (tokens[p].str[0] == '_' || issmall(tokens[p].str[0]) || isbig(tokens[p].str[0]))
	{
		for (int i = 0; i < len[p]; i++)
		{
			char c = tokens[p].str[i];
			if (c != '_' && !issmall(c) && !isbig(c) && !isdigit(c)) return 0;
		}
		return 4;
	}

	//number
	int cnt_dot = 0, pos = 0;
	for (int i = 0; i < len[p]; i++)
	{
		char c = tokens[p].str[i];
		if (c == '.') ++cnt_dot, pos = i;
		else if (!isdigit(c)) return 0;
	}
	if (cnt_dot > 1) return 0;
	//for an int number, no dot, no pre zero
	if (cnt_dot == 0)
	{
		if (tokens[p].str[0] == '0' && len[p] > 1) return 0;
		return 2;
	}
	if (tokens[p].str[0] == '0' && pos != 1) return 0;
	if (pos == 0) return 0;
	if (pos == len[p] - 1) return 0;
	return 3;
}

//计算int值
int calc_int(int p)
{
	int num = 0;
	for (int i = 0; i < len[p]; i++)
	{
		num *= 10;
		num += tokens[p].str[i] - '0';
	}
	return num;
}

//计算float值
double calc_float(int p)
{
	int pos = 0;
	dl num = .0;
	while (tokens[p].str[pos] != '.') ++pos;
	dl now = 1;
	for (int i = pos - 1; ~i; i--)
	{
		num += (tokens[p].str[i] - '0') * now;
		now *= 10;
	}
	now = .1;
	for (int i = pos + 1; i < len[p]; i++)
	{
		num += (tokens[p].str[i] - '0') * now;
		now /= 10;
	}
	return num;
}

//bel代表变量哈希值
typedef struct value
{
	enum
	{
		INT, FLOAT, VARIABLE, ERROR
	} type;
	dl fVal;
	int iVal;
	int bel;
} Value;

const Value error = { ERROR, 0, 0, 0 }, zero = { INT, 0, 0, 0 };

int _stack[N], _t;
bool flag;
bool check_parentheses(int l, int r)
{
	_t = 0;
	for (int i = l; i <= r; i++)
	{
		if (tokens[i].op == '(') _stack[++_t] = i;//这里将stack的值置为index，比较直接
		if (tokens[i].op == ')')
		{
			if (!_t)
			{  //to be continue
				flag = false;
				return false;
			}
			if (i == r && _stack[_t] == l) return true;
			--_t;
		}
	}
	if (_t) flag = false;
	return false;
}

Value merge(Value X, Value Y, char op)
{
	Value rem;
	if (X.type == ERROR || Y.type == ERROR) return error;
	if (op == '=')
	{
		if (X.type != VARIABLE) return error;
		return Y;
	}
	if (X.type == VARIABLE) return error;
	if (op == '+')
	{
		if (X.type == INT)
		{
			if (Y.type == INT) rem.type = INT, rem.iVal = X.iVal + Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.iVal + Y.fVal;
		}
		else
		{
			if (Y.type == INT) rem.type = FLOAT, rem.fVal = X.fVal + Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.fVal + Y.fVal;
		}
	}
	else if (op == '-')
	{
		if (X.type == INT)
		{
			if (Y.type == INT) rem.type = INT, rem.iVal = X.iVal - Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.iVal - Y.fVal;
		}
		else
		{
			if (Y.type == INT) rem.type = FLOAT, rem.fVal = X.fVal - Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.fVal - Y.fVal;
		}
	}
	else if (op == '*')
	{
		if (X.type == INT)
		{
			if (Y.type == INT) rem.type = INT, rem.iVal = X.iVal * Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.iVal * Y.fVal;
		}
		else
		{
			if (Y.type == INT) rem.type = FLOAT, rem.fVal = X.fVal * Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.fVal * Y.fVal;
		}
	}
	else if (op == '/')
	{
		if (X.type == INT)
		{
			if (Y.type == INT) rem.type = INT, rem.iVal = X.iVal / Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.iVal / Y.fVal;
		}
		else
		{
			if (Y.type == INT) rem.type = FLOAT, rem.fVal = X.fVal / Y.iVal;
			else rem.type = FLOAT, rem.fVal = X.fVal / Y.fVal;
		}
	}
	return rem;
}

void printValue(Value v)
{
	if (v.type == ERROR) puts("Error");
	else if (v.type == INT) printf("%d\n", v.iVal);
	else printf("%.6lf\n", v.fVal);
}

//rem_var代表目前这一行被赋值的变量 _计数
//assignment代表到上一行末尾为止被赋值的变量 tot计数
Value assignment[N], rem_var[N];
int _, tot;

Value eval(int l, int r)
{
	if (l > r) return error;
	if (l == r)
	{
		if (tokens[l].type == 4)
		{    //variable
			int rem_hash = hash(tokens[l].str, tokens[l].str + 32);
			for (int i = 1; i <= tot; i++)
			{
				if (assignment[i].bel == rem_hash) return assignment[i];
			}
			return error;
		}
		Value rem = error;
		if (tokens[l].type == 2)
		{    //int
			rem.type = INT;
			rem.iVal = tokens[l].iVal;
		}
		if (tokens[l].type == 3)
		{    //float
			rem.type = FLOAT;
			rem.fVal = tokens[l].fVal;
		}
		return rem;
	}
	flag = true;
	if (check_parentheses(l, r)) return eval(l + 1, r - 1);
	if (!flag) return error;
	int pos = 0, mx = 100, now = 0;
	for (int i = l; i <= r; i++)
	{
		if (tokens[i].type != 1) continue;
		if (tokens[i].op == '(') ++now; //又使用stack的思想
		else if (tokens[i].op == ')') --now;
		else if (!now && i > l && !iscalc(tokens[i - 1].type == 1 ? tokens[i - 1].op : 0) && iscalc(tokens[i].op))
		{
			if (bel[tokens[i].op] <= mx) mx = bel[tokens[i].op], pos = i;
		}
	}

	if (mx == -1) return error;   //如果找到的运算符是‘=’
	if (pos) return merge(eval(l, pos - 1), eval(pos + 1, r), tokens[pos].op);  //如果找到了主运算符
	if (!pos && (tokens[l].op == '-')) return merge(zero, eval(l + 1, r), '-'); //如果找不到主运算符，且存在负号
	return error;
}

Value evalAssign(int l, int r)
{
	if (l < r && tokens[l].type == 4 && tokens[l + 1].type == 1 && tokens[l + 1].op == '=')
	{   //“variable=” 格式
		int rem_hash = hash(tokens[l].str, tokens[l].str + 32);
		++_;
		rem_var[_] = evalAssign(l + 2, r);
		rem_var[_].bel = rem_hash;
		return rem_var[_];
	}
	else
	{
		return eval(l, r);
	}
}

int main(void)
{
	// freopen("data.in", "r", stdin);
	//赋优先级
	bel['='] = -1;
	bel['+'] = bel['-'] = 1;
	bel['*'] = bel['/'] = 2;
	bool Flag = true;
	while (scanf("%s", tokens[++cnt].str) != EOF)
	{
		len[cnt] = strlen(tokens[cnt].str);
		// word analysis
		// 1 denotes operator
		// 2 denotes int
		// 3 denotes float
		// 4 denotes variable
		if ((tokens[cnt].type = word_analysis(cnt)) == 0)
		{
			Flag = false; //词法错误
		}
		if (tokens[cnt].type == 2) tokens[cnt].iVal = calc_int(cnt);
		if (tokens[cnt].type == 3) tokens[cnt].fVal = calc_float(cnt);
		char c = getchar();
		if (c == '\n')
		{
			Value res = Flag ? evalAssign(1, cnt) : error;
			if (res.type != ERROR)
			{  //new variable 存储 old variable 覆盖
				while (_)
				{
					bool tag = false;
					for (int i = 1; i <= tot; i++)
					{
						if (assignment[i].bel == rem_var[_].bel)
						{
							assignment[i] = rem_var[_];
							tag = true;
							break;
						}
					}
					if (!tag) assignment[++tot] = rem_var[_];
					rem_var[_] = zero;
					--_;
				}
			}
			while (cnt)
			{
				tokens[cnt].fVal = tokens[cnt].iVal = tokens[cnt].op = tokens[cnt].type = 0;
				memset(tokens[cnt].str, 0, sizeof tokens[cnt].str);
				--cnt;
			}
			_ = 0;
			Flag = true;
			printValue(res);
		}
	}

}
