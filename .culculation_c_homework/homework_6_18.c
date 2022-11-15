//
// Created by xiexu on 2022/10/17.
//

/*
 * 定义数组input 101
 *
 * 任意输入
 *
 * for(int i = 0; <101)
 * if（one_back_crime[i] !=' ' ）
 * printf
 */

//0 ~ 31和127(共)为控制字符或通信专用字符(其余为可显示字符)，
// 如控制字符:LF(换行)、CR(回车)、FF(换页)、DEL(删除)、BS(退格)、BEL(环)等。
// 用于通信的特殊字符:SOH(文本头)、EOT(文本尾)、ACK(确认)等。

//ASCII值8、9、10和13分别转换为退格符、制表符、换行符和回车符。
// 它们没有特定的图形显示，但是根据应用程序的不同，它们对文本显示有不同的效果。

#include <stdio.h>

int main(void)
{
	char input[101] = { 0 };
	int len = -1;
	while (scanf("%c", &input[++len]) != EOF);

//	fgets(one_back_crime, 101, stdin);

	for (int i = 0; i < 100; i++)
	{
		if (input[i] == '\n')
		{
			break;
		}
		if (input[i] != ' ')
		{
			printf("%c", input[i]);
		}
	}

	return 0;
}