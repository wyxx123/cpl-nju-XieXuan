#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 1005

int hash[N];

int main(int argc, char *argv[])
{
    int Q, num, x;
    char operation[15];
    scanf("%d%d", &Q, &num);
    while (Q--)
    {
        scanf("%s%d", operation, &x);
        if (strcmp(operation, "Add") == 0)
        {
            ++hash[x - num];
        }
        else if (strcmp(operation, "Query") == 0)
        {
            int sum = 0;
            for (int i = 1000; i >= 0; --i)
            {
                sum += hash[i];
                if (sum >= x)
                {
                    printf("%d\n", i + num);
                    break;
                }
            }
            if (sum < x)
            {
                printf("No Answer\n");
            }
        }
        else
        {
            printf("%s\n", operation);
        }
    }
    return 0;
}
