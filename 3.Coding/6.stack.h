/*************************************************************************
	> File Name: 6.stack.h
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Jul 2024 06:54:47 AM CST
 ************************************************************************/

#ifndef _6_STACK_H
#define _6_STACK_H

typedef struct Stack{
    int *data;
    int top;
    int size;
    int count;
} Stack;

Stack *initStack(int n);

int empty(Stack * s);

int push(Stack * s, int value);

int pop(Stack * s);

int top(Stack * s);

void clearStack(Stack * s);


void showStack(Stack * s);

#endif
