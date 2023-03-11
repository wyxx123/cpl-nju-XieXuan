#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define isdigit(ch) (ch >= '0' && ch <= '9')
#define N 1005
#define TOTAL 25000005

typedef struct Node
{
    int data, next, prev;
}Node;

Node node[TOTAL];
int head[N], tail[N], length[N], pos, now[N];

int read()
{
    int n = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
    return n;
}

int main(int argc, char *argv[])
{
    int n = read(), m = read(), q = read();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            node[++pos].data = read();
            if (i == 1)
            {
                head[j] = tail[j] = pos;
                length[j] = n;
                continue;
            }
            node[tail[j]].next = pos;
            node[pos].prev = tail[j];
            tail[j] = pos;
        }
    }
    while (q--)
    {
        int x = read(), y = read();
        node[head[y]].prev = tail[x];
        node[tail[x]].next = head[y];

        head[y] = tail[x];
        tail[x] = node[tail[x]].prev;
        node[node[tail[x]].next].prev = 0;
        node[tail[x]].next = 0;

        --length[x];
        ++length[y];
    }
    int maxlen = 1;
    for (int i = 1; i <= m; ++i)
        maxlen = max(maxlen, length[i]);
    for (int i = maxlen; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (length[j] == i)
            {
                now[j] = head[j];
                printf("%5d", node[now[j]].data);
            }
            else if (length[j] > i)
            {
                now[j] = node[now[j]].next;
                printf("%5d", node[now[j]].data);
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");
    }
    return 0;
}
