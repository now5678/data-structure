/*************************************************************************
	> File Name: 6.priority_queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Jul 2024 10:27:50 AM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAxNum 20
#define FA(n) ((n) - 1) / 2
#define LCD(n) (n) * 2 + 1
#define RCD(n) ((n) + 1) * 2

typedef struct priority_queue
{
    int * data;
    int size, count;
} queue;

queue * initQueue(int size)
{
    queue * q = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->count = 0;
    q->data = (int *)malloc(sizeof(int) * size);
    return q;
}

int empty(queue * q)
{
    return q->count == 0;
}

int full(queue * q)
{
    return q->count == q->size;
}

void clear(queue * q)
{
    if (q == NULL) return;
    if (q->data != NULL) free(q->data);
    free(q);
    return ;
}

void up_update(int * arr, int n)
{
    if (n == 0) return;
    int parent = FA(n), lchild = LCD(parent), rchild = RCD(parent), max;
    
    if (arr[parent] >= arr[lchild]) max = parent; else max = lchild;
    if (rchild <= n && arr[max] < arr[rchild]) max = rchild;
    if (max == parent)
    {
        return ;
    }
    int tmp = arr[max];
    arr[max] = arr[parent];
    arr[parent] = tmp;
    up_update(arr, parent);
    return ;
}

int push(queue * q, int value)
{
    if (full(q)) return 0;
    q->data[q->count++] = value;
    up_update(q->data, q->count - 1);
    return 1;
}

void down_update(int * arr, int parent, int scope)
{
    if (parent <= 0) return;
    int lchild = LCD(parent), rchild = RCD(parent), max = parent;
    if (lchild < scope && arr[parent] >= arr[lchild]) max = parent; else max = lchild;
    if (rchild < scope && arr[max] < arr[rchild]) max = rchild;
    if (max == parent)
    {
        return ;
    }
    int tmp = arr[max];
    arr[max] = arr[parent];
    arr[parent] = tmp;
    parent = max;
    down_update(arr, parent, scope);
    return ;
}

int pop (queue * q)
{
    if(empty(q)) return 0;
    q->data[0] = q->data[--q->count];
    down_update(q->data, 0, q->count);
    return 1;
}
int front(queue * q, int * value)
{
    if (empty(q)) return 0;
    *value = q->data[0];
    return 1;
}

void showQueue(queue * q)
{
    for (int i = 0; i < q->count; ++i)
    {
        printf("%3d", q->data[i]);
    }
    printf("\n");
    return ;
}


int main ()
{
    srand(time(0));
    queue * q = initQueue(MAxNum);
    for (int i = 0; i < MAxNum; ++i)
    {
        int no = rand() % 5;
        switch(no)
        {
            case 0:
            case 1:
            case 2:
            {
                int value = rand() % 100;
                printf("push %3d into queue = %d\n", value, push(q, value));
            } break;
            case 3:
            case 4:
            {
                int value;
                front(q, &value);
                printf("pop %3d from queue = %d\n", value, pop(q));
            } break;
        }
        showQueue(q);
    }
    return 0;
}
