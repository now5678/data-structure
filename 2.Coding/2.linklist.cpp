/*************************************************************************
	> File Name: 2.linklist.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Jun 2024 08:01:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int value;
    struct Node * next;
} *linklist , Node;

linklist getNode(int value);

void clear(linklist p);

int insert(linklist p, int pos, int value);

int main()
{
    linklist p = getNode(20);
    clear(p);
    srand(time(0));
    #define MaxSize 20
    for (int i = 0; i < 2; ++i)
    {
        int pos = rand() % (i + 1);
        int value = rand() % 100;
        printf("insert %d into %d in linklist = %d\n", value, pos, insert(p, pos, value));
    }
    clear(p);

    return 0;
}

linklist getNode(int value)
{
    linklist head = (linklist)malloc(sizeof(Node));
    head->value = value;
    head->next = NULL;
    return head;
}

void clear(linklist p)
{
    if (p == NULL) return ;
    int n = 0;
    for (linklist q = p; q; p = q)
    {
        q = q->next;
        free(p);
        ++n;
    }
    printf("清理完成，共清理 %d 个元素!\n", n);
    return ;
}

int insert(linklist p, int pos, int value)
{
    if (pos == 0)
    {
        linklist q = getNode(value);
        q->next = p;
        p = q;
        return 1;
    }
    linklist q = p;
    int nums = 0;
    while(q)
    {
        q = q->next;
        nums++;
    }
    if (pos > nums)
    {
        return 0;
    }
    q = p;
    for (int i = 0; i < pos; ++i)
    {
        q = q->next;
    }
    linklist tmp = getNode(value);
    tmp->next = q->next;
    q->next = tmp;
    return 1;
}




