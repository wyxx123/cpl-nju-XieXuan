#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <time.h>
#define getCommand(num) ("mixer.exe < mixer_data/mixer_" + to_string(num) + ".in > mixer_data/mixer_" + to_string(num) + ".out").c_str()
#define getFilename(num) ("mixer_data/mixer_" + to_string(num) + ".in").c_str()

template <typename T>
T random(T l, T r)
{
    unsigned long long num = rand() * rand();
    return (T)(num % (unsigned long long)(r - l + 1) + (unsigned long long)l);
}

char getChar(int num)
{
    if (num <= 9)
        return num + '0';
    return num - 10 + 'A';
}

void outputNum(int num)
{
    printf("%c%c", getChar(num / 16), getChar(num % 16));
}

std::string to_string(int x)
{
    std::string ans = "";
    while (x)
    {
        ans = (char)(x % 10 + '0') + ans;
        x /= 10;
    }
    return ans;
}

int main(int argc, char *argv[])
{
	system("mkdir mixer_data"); 
    srand(time(NULL));
    for (int i = 1; i <= 25; ++i)
    {
        freopen(getFilename(i), "w", stdout);
        int T = random(1, 1000000);
        printf("%d\n", T);
        while (T--)
        {
            int numa[3], numb[3];
            int x, y;
            x = random(0, 255), y = random(0, 255 - x);
            numa[0] = x, numb[0] = y;
            x = random(0, 255), y = random(0, 255 - x);
            numa[1] = x, numb[1] = y;
            x = random(0, 255), y = random(0, 255 - x);
            numa[2] = x, numb[2] = y;
            printf("#");
            outputNum(numa[0]);
            outputNum(numa[1]);
            outputNum(numa[2]);
            printf(" #");
            outputNum(numb[0]);
            outputNum(numb[1]);
            outputNum(numb[2]);
            printf("\n");
        }
        fclose(stdout);
        system(getCommand(i));
    }
    return 0;
}
