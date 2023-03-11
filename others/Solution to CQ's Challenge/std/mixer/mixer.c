#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define isdigit(ch) ((ch) >= '0' && (ch) <= '9')

char a[10], b[10];

int getNum(char x)
{
    if (isdigit(x))
        return x - '0';
    return x - 'A' + 10;
}

char getChar(int num)
{
    if (num <= 9)
        return num + '0';
    return num - 10 + 'A';
}

void add(char* x, char* y)
{
    int sum = 16 * getNum(x[0]) + getNum(x[1]) + 16 * getNum(y[0]) + getNum(y[1]);
    printf("%c%c", getChar(sum / 16), getChar(sum % 16));
}

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", a, b);
        printf("#");
        add(a + 1, b + 1);
        add(a + 3, b + 3);
        add(a + 5, b + 5);
        printf("\n");
    }
    return 0;
}