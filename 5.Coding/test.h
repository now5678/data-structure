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

#define BIGNUM 10000000
#define SMALLNUM 10000

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
    fun(tmp, n);\
    long long a = clock();\
    if(check(tmp, n))\
    {\
        printf("\nOK\n");\
    }else{\
        printf("\nfailure\n");\
    }\
    printf("arr[0] : %d\n", tmp[0]);\
    free(tmp);\
    printf("%s : %ditems use %lld ms\n", #fun, n, 1000 * (a - b) / CLOCKS_PER_SEC);\
}

#define LCD(n) (n) * 2 + 1
#define RCD(n) ((n) + 1) * 2
#define PA(n) ((n) - 1) / 2

#endif
