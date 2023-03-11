#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <time.h>
#define getCommand(num) ("tower.exe < tower_data/tower_" + to_string(num) + ".in > tower_data/tower_" + to_string(num) + ".out").c_str()
#define getFilename(num) ("tower_data/tower_" + to_string(num) + ".in").c_str()

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
	system("mkdir tower_data"); 
    srand(time(NULL));
    for (int k = 1; k <= 20; ++k)
    {
        freopen(getFilename(k), "w", stdout);
        int n, m, q;
        if (k <= 6)
        {
            n = random(5, 100), m = random(5, 100), q = random(1, 1000);
        }
        else if (k <= 12)
        {
            n = random(5, 1000), m = random(5, 1000), q = random(1, 10000);
        }
        else
        {
            n = random(5, 25000), m = random(5, 1000), q = random(1, 100000);
        }
        n = 25000, m = 100, q = 100000;
        int *a = (int *)malloc(sizeof(int) * (m + 5));
        for (int i = 1; i <= m; ++i)
            a[i] = n;
        printf("%d %d %d\n", n, m, q);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j < m; ++j)
                printf("%d ", random(0, 999));
            printf("%d\n", random(0, 999));
        }
        for (int i = 1; i <= q; ++i)
        {
            int from = random(1, m), to = m;
            while (from == to || a[from] == 1)
                from = random(1, m), to = m;
            printf("%d %d\n", from, to);
            --a[from], ++a[to];
        }
        free(a);
        fclose(stdout);
        system(getCommand(k));
    }
    return 0;
}
