#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <time.h>
#define getCommand(num) ("kth.exe < kth_data/kth_" + to_string(num) + ".in > kth_data/kth_" + to_string(num) + ".out").c_str()
#define getFilename(num) ("kth_data/kth_" + to_string(num) + ".in").c_str()

template <typename T>
T random(T l, T r)
{
    unsigned long long num = rand() * rand();
    return (T)(num % (unsigned long long)(r - l + 1) + (unsigned long long)l);
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
	system("mkdir kth_data"); 
    srand(time(NULL));
    for (int i = 1; i <= 20; ++i)
    {
        freopen(getFilename(i), "w", stdout);
        int Q, num;
        num = random(-0x00ffffff, 0x00ffffff);
        if (i <= 6)
        {
            Q = random(1, 1000);
        }
        else if (i <= 10)
        {
            Q = random(1000, 10000);
        }
        else
        {
            Q = random(10000, 100000);
        }
        int sum = 0;
        printf("%d %d\n", Q, num);
        while (Q--)
        {
            int posibility = random(0, 10000);
            if (posibility <= 1)
            {
                printf("Sakiyary %d\n", random(num, num + 999));
            }
            else if (posibility <= 2)
            {
                printf("Tilnel %d\n", 233);
            }
            else if (posibility <= 3)
            {
                printf("Fuck %d\n", -0x7f7f7f7f);
            }
            else
            {
                posibility = random(0, 1);
                if (posibility)
                {
                    ++sum;
                    printf("Add %d\n", random(num, num + 999));
                }
                else
                {
                    printf("Query %d\n", random(1, sum + 3));
                }
            }
        }
        fclose(stdout);
        system(getCommand(i));
    }
    return 0;
}
