/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Jul 2024 08:22:29 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGNUM 50000
#define SMALLNUM 5000

#define SWAP(a, b) \
{\
    __typeof(a) __c = a;\
    a = b;\
    b = __c;\
}

__attribute__((constructor))
void initRand()
{
    printf("init rand\n");
    srand(time(0));
}

int *getRandArr(int n)
{
    int * arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 10000;
    }
    return arr;
}

int check(int * arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

#define TEST(fun, arr, n) {\
    printf("fun : %s", #fun);\
    int *tmp = (int *)malloc(sizeof(int) * n);\
    memcpy(tmp, arr, n);\
    long long b = clock();\
    fun(tmp, 0, n);\
    long long a = clock();\
    if(check(tmp, n))\
    {\
        printf(" OK ");\
    }else{\
        printf(" failure");\
    }\
    free(tmp);\
    printf(" %d items use %lld ms\n", n, 1000 * (a - b) / CLOCKS_PER_SEC);\
}

#define LCD(n) (n) * 2 + 1
#define RCD(n) ((n) + 1) * 2
#define PA(n) ((n) - 1) / 2

#endif
