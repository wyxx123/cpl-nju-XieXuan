//
// Created by xiexu on 2023/2/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 100
#define MAX_STR_NUM 100
// 将字符串按照指定的分隔符分割成多个子串，并将这些子串存储到一个字符串数组中
char **strsplit(char *str, char *delim)
{
	char **res = NULL;
	char *token = NULL;
	int count = 0;
	// 分配字符串数组
	res = (char **)malloc(MAX_STR_NUM * sizeof(char *));
	if (res == NULL)
	{
		printf("Error: malloc failed!\n");
		return NULL;
	}
	// 使用 strtok() 函数将字符串按照指定的分隔符分割成多个子串
	token = strtok(str, delim);
	while (token != NULL)
	{
		// 将分割后的子串存储到字符串数组中
		res[count] = (char *)malloc(MAX_STR_LEN * sizeof(char));
		if (res[count] == NULL)
		{
			printf("Error: malloc failed!\n");
			return NULL;
		}
		strcpy(res[count], token);
		count++;
		// 继续分割
		token = strtok(NULL, delim);
	}
	return res;
}
// 对字符串数组进行排序，以获得字典序排列的结果
void sort_str_array(char **str_array, int num)
{
	int i, j;
	char *temp;
	// 使用冒泡排序法对字符串数组进行排序
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			// 使用 strcmp() 函数比较两个字符串的大小
			if (strcmp(str_array[j], str_array[j + 1]) > 0)
			{
				// 交换两个字符串
				temp = str_array[j];
				str_array[j] = str_array[j + 1];
				str_array[j + 1] = temp;
			}
		}
	}
}
int main()
{
	char str[MAX_STR_LEN];
	char delim[2];
	char **str_array;
	int num;
	int i;
	// 输入字符串和分隔符
	printf("Please input the string: ");
	scanf("%s", str);
	printf("Please input the delimiter: ");
	scanf("%s", delim);
	// 将字符串按照指定的分隔符分割成多个子串，并将这些子串存储到一个字符串数组中
	str_array = strsplit(str, delim);
	if (str_array == NULL)
	{
		printf("Error: strsplit failed!\n");
		return -1;
	}
	// 计算字符串数组中的字符串数量
	num = 0;
	while (str_array[num] != NULL)
	{
		num++;
	}
	// 对字符串数组进行排序，以获得字典序排列的结果
	sort_str_array(str_array, num);
	// 输出排序后的结果
	printf("The sorted result is:\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\n", str_array[i]);
	}
	return 0;
}