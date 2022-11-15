//
// Created by xiexu on 2022/11/4.
//
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("%d%c%s\n", 0, 0, "EOT");

	bool is_have_meet_zero = false;
	int count = 0;
	for (int i = 0; (!is_have_meet_zero) && (i < 100); i++)
	{
		char tmp = 0;
		scanf("%c", &tmp);
		if (tmp == 0)
			is_have_meet_zero = true;
		else
			printf("judge fail %d time(s)\n", ++count);
	}
	if (is_have_meet_zero)
		printf("have found it!!!");
}




