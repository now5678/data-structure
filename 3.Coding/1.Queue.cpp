/*************************************************************************
	> File Name: 1.Queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Jun 2024 03:54:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector{
    int *data;
} vector;

vector * initVector(int n)
{
    vector *v = (vector *)malloc(sizeof(vector));
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

int vectorSeek(vector * v, int pos)
{
    return v->data[pos];
}

void insertVector(vector *v, int pos, int val)
{
    v->data[pos] = val;
}

void clearVector(vector *v)
{
    free(v);
}

typedef struct Queue{
    vector *data;
    int size, head, tail, count;
} Queue;

Queue * initQueue(int n)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->size = n;
    q->tail = q->head = q->count = 0;
    q->data = initVector(n);
    return q;
}

int empty(Queue *q){
    return q->count == 0;
}
int front(Queue *q){
    return vectorSeek(q->data, q->head);
}
int push(Queue *q, int val){
    if (q->size == q->count) return 0;
    insertVector(q->data, q->tail, val);
    q->tail++;
    q->count++;
    if (q->tail == q->size) q->tail = 0;
    return 1;
}
int pop(Queue *q){
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->size) q->head = 0;
    q->count--;
    return 1;
}
void clearQueue(Queue *q)
{
    if(q == NULL)
    {
        return;
    }
    clearVector(q->data);
    free(q);
    return ;
}
void showQueue(Queue * q)
{
    static int count = 0;
    printf("%3d. ", count++);
    for(int i = 0; i < q->count; ++i)
    {
        printf("%3d", vectorSeek(q->data, (q->head + i) % q->size));
    }
    printf("\n");
    printf("the front of queue = %d\n", front(q));
}

int main()
{
    Queue *q = initQueue(10);
    srand(0);
    for (int i = 0; i < 20; ++i)
    {
        int no = random() % 5;
        switch(no)
        {
            case 0:
            case 1:
            case 2:
            {
                int val = random() % 100;
                printf("push %d into queue = %d\n", val, push(q, val));
            }
                break;
            case 3:
            case 4:
                printf("pop from queue = %d\n", pop(q));
                break;
        }
        showQueue(q);
    }
    return 0;
}

