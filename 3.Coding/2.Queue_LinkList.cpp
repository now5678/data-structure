/*************************************************************************
	> File Name: 2.Queue_LinkList.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Jun 2024 07:27:25 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int value;
    struct Node *next;
}  Node;

typedef struct LinkList{
    Node head;
    struct Node *tail;
} LinkList;

typedef struct Queue
{
    LinkList * data;
    int count;
} Queue;

Node *getNode()
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
    return n;
}



LinkList * initLinkList()
{
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->tail = &l->head;
    return l;
}

Queue * initQueue()
{
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->data = initLinkList();
    q->count = 0;
    return q;
}

int empty(Queue * q)
{
    return q->count == 0;
}
int front(Queue *q)
{
    return q->data->head.next->value;
}

int insertTail(LinkList *l, int value)
{
    Node * n = getNode();
    n->value = value;
    l->tail->next = n;
    l->tail = l->tail->next;
    return 1;
}
int push(Queue *q, int value)
{
    int result = insertTail(q->data, value);
    if (result) q->count++;
    return result;
}

int removeHead(LinkList *l)
{
    Node * n = l->head.next;
    l->head.next = n->next;
    if (n == l->tail)
    {
        l->tail = &l->head;
    }
    free(n);
    return 1;
}
int pop(Queue *q)
{
    if (empty(q)) return 0;
    q->count--;
    return removeHead(q->data);    
}

void clearLinklist(LinkList * l)
{
    while(l->head.next)
    {
        Node *next = l->head.next->next;
        free(l->head.next);
        l->head.next = next;
    }
    l->tail = &l->head;
    return ;
}

void clearQueue(Queue *q)
{
    if (q == NULL) return;
    clearLinklist(q->data);
    free(q);
    q = NULL;
    return ;
}

void showQueue(Queue * q)
{
    Node* v = q->data->head.next;
    while(v)
    {
        printf("%3d", v->value);
        v = v->next;
    }
    printf("\n");
    return ;
}


int main()
{
    Queue * q = initQueue();
    srand(0);
    for(int i = 0; i < 20; ++i)
    {
        int no = rand() % 5;
        switch(no)
        {
            case 0:
            case 1:
            case 2:
            {
                int value = rand() % 100;
                printf("push %d into queue = %d\n", value, push(q, value));
            }
            break;
            case 3:
            case 4:
            {
                printf("pop from queue = %d\n", pop(q));
            }
            break;
        }
        showQueue(q);
    }
    return 0;
}
