/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 09:25:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector
{
    int *arr;
    int count;
    int size;
} vector;

vector * initVector(int n);

int insert(vector * v, int pos, int e);

void print_vector(vector * v);

int erase(vector * v, int pos);

void clear(vector * v);

int main()
{
    srand(time(0));
    #define MaxSize 20
    vector * v = initVector(MaxSize);
    for (int i = 0; i < 20; ++i)
    {
        int no = rand() % 4;
        switch(no)
        {
            case 0:
            case 1:
            case 2:
            {
                int pos = rand() % (v->count + 2);
                int value = rand() % 100;
                printf("insert %d into %d in vector = %d\n", value, pos, insert(v, pos, value));
            }
                break;
            case 3:
            {
                int pos = rand() % (v->count + 1);
                printf("delete pos = %d from vector = %d\n", pos, erase(v, pos));
            }
                break;
        }
        print_vector(v);
    }
    clear(v);
    return 0;
}

vector * initVector(int n)
{
    vector * tmp = (vector *)malloc(sizeof(vector));
    tmp->count = 0;
    tmp->arr = (int *)malloc(sizeof(int) * n);
    tmp->size = n;
    return tmp;
}

int insert(vector * v, int pos, int e)
{
    if (pos < 0 || pos > v->count) return 0;
    if (v->count == v->size) return 0;
    for (int i = v->count; i > pos; --i)
    {
        v->arr[i] = v->arr[i - 1];
    }
    v->arr[pos] = e;
    ++(v->count);
    return 1;
}

int erase(vector * v, int pos)
{
    if (pos < 0 || pos >= v->count) return 0;
    for (int i = pos; i < v->count - 1; ++i)
    {
        v->arr[i] = v->arr[i + 1];
    }
    v->count--;
    return 1;
}

void print_vector(vector * v)
{
    int len = 0;
    for (int i = 0; i < v->size; ++i)
    {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; ++i)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < v->count; ++i)
    {
        
        printf("%3d", v->arr[i]);
    }
    printf("\n\n\n");
    return ;
}  

void clear(vector * v)
{
    if (v == NULL) return ;
    free(v);
    printf("clear\n");
}
