//
// Created by xiexu on 2023/2/25.
//
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200009
char array[MAX_LEN] = { 0 };

int main(void)
{
	int q = 0;
	int len = 0;
	scanf("%d%d", &len, &q);
	scanf("%s", array);
	for (int i = 0; i < q; i++)
	{
		char input = 0;
		scanf(" %c", &input);
		if (input == 'Q')
		{
			int index = 0;
			scanf("%d", &index);
			printf("%c\n", array[index - 1]);
		}
		else
		{
			int index = 0;
			char insert[2023] = { 0 };
			scanf("%d%2023s", &index, insert);
			int insert_len = strlen(insert);
			for (int j = len - 1; j >= index; j--)
			{
				array[j + insert_len] = array[j];
			}
//			strncpy(array + index, insert, insert_len);
			for (int j = index, k = 0; k < insert_len; j++, k++)
			{
				array[j] = insert[k];
			}
			len += insert_len;
		}

	}
	return 0;
}
