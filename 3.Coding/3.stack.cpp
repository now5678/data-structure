/*************************************************************************
	> File Name: 3.stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Jun 2024 07:27:44 AM CST
 ************************************************************************/

#include "6.stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Stack *initStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->count = 0;
    return s;
}

int empty(Stack * s)
{
    return s->count == 0;
}

int push(Stack * s, int value)
{
    if(s->size == s->count) return 0;
    s->top++;
    s->data[s->top] = value;
    s->count++;
    return 1;
}

int pop(Stack * s)
{
    if(empty(s)) return 0;
    s->top--;
    s->count--;
    return 1;
}
int top(Stack * s)
{
    if(empty(s)) return 0;
    return s->data[s->top];
}

void clearStack(Stack *s)
{
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}
void showStack(Stack * s)
{
    if (s == NULL || empty(s)) return;
    for(int i = 0; i <= s->top; ++i)
    {
        printf("%3d", s->data[i]);
    }
    printf("\n");
    return ;
}

int main()
{
    srand(0);
    Stack * s = initStack(5);
    for (int i = 0; i < 20; ++i)
    {
        int no = rand() % 5;
        switch(no)
        {
            case 0:
            case 1:
            case 2:
            {
                int value = rand() % 100;
                printf("push %d into stack = %d\n", value, push(s, value));
                break;
            }
            case 3:
            case 4:
            printf("pop %d from stack = %d\n", top(s), pop(s));
            break;
        }
        showStack(s);
    }
    return 0;
}
