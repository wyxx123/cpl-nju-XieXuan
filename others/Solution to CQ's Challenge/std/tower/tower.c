#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 1005
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct LinkNode
{
    int data;
    struct LinkNode *prev, *next;
}LinkNode;

typedef struct LinkList
{
    int len;
    LinkNode *head, *tail;
}LinkList;

LinkList list[N];
LinkNode *now[N];

void PushBack(LinkList* li, int num)
{
    if (li->head == NULL)
    {
        li->len = 1;
        li->head = malloc(sizeof(LinkNode));
        li->head->data = num;
        li->head->next = li->head->prev = NULL;
        li->tail = li->head;
    }
    else
    {
        ++li->len;
        LinkNode* node = malloc(sizeof(LinkNode));
        li->tail->next = node;
        node->prev = li->tail;
        node->next = NULL;
        node->data = num;
        li->tail = node;
    }
}

void PushFront(LinkList* li, int num)
{
    if (li->head == NULL)
    {
        li->len = 1;
        li->head = malloc(sizeof(LinkNode));
        li->head->data = num;
        li->head->next = li->head->prev = NULL;
        li->tail = li->head;
    }
    else
    {
        ++li->len;
        LinkNode* node = malloc(sizeof(LinkNode));
        li->head->prev = node;
        node->next = li->head;
        node->prev = NULL;
        node->data = num;
        li->head = node;
    }
}

int PopBack(LinkList* li)
{
    --li->len;
    int num = li->tail->data;
    li->tail = li->tail->prev;
    free(li->tail->next);
    li->tail->next = NULL;
    return num;
}

int main(int argc, char *argv[])
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; ++i)
        list[i].head = list[i].tail = NULL, list[i].len = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int x;
            scanf("%d", &x);
            PushBack(&list[j], x);
        }
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        PushFront(&list[y], PopBack(&list[x]));
    }
    int maxlen = 1;
    for (int i = 1; i <= m; ++i)
        maxlen = max(maxlen, list[i].len);
    for (int i = maxlen; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (list[j].len == i)
            {
                now[j] = list[j].head;
                printf("%5d", now[j]->data);
            }
            else if (list[j].len > i)
            {
                now[j] = now[j]->next;
                printf("%5d", now[j]->data);
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