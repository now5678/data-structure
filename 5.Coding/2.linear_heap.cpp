/*************************************************************************
	> File Name: 2.linear_heap.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Jul 2024 08:21:28 PM CST
 ************************************************************************/

#include "test.h"

int *getRandArr(int n)
{
    int * arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
    return arr;
}

void down_update(int * arr, int parent, int n)
{
    while (LCD(parent) < n)
    {
        int lchild = LCD(parent), rchild = RCD(parent), max = parent;
        if (arr[parent] < arr[lchild]) max = lchild;
        if (rchild < n && arr[max] < arr[rchild]) max = rchild;
        if (max == parent)
        {
            return;
        }
        SWAP(arr[max], arr[parent]);
        parent = max;
    }
    return ;
}

void heap_sort_final(int * arr, int n)
{
    for(int i = n - 1; i > 1; --i)
    {
        SWAP(arr[0], arr[i]);
        down_update(arr, 0, i);
    }
}

void linear_heap_build(int * arr, int n)
{ 
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        down_update(arr, i, n);
    }
}

void linear_heap(int * arr, int n)
{
    linear_heap_build(arr, n);
    heap_sort_final(arr, n);
    return ;
}

void up_update(int * arr, int ind)
{
    while(PA(ind) >= 0)
    {
        int parent = PA(ind), max = parent;
        if (arr[parent] < arr[ind]) max = ind;
        if(max == parent) return;
        SWAP(arr[parent], arr[ind]);
        ind = parent;
    }
}

void normal_heap_build(int * arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        up_update(arr, i);
    }
    return ;
}

void normal_heap(int * arr, int n)
{
    normal_heap_build(arr, n);
    heap_sort_final(arr, n);
    return ;
}

int main()
{
    int * arr = getRandArr(BIGNUM);
    TEST(linear_heap, arr, BIGNUM);
    TEST(normal_heap, arr, BIGNUM);
    return 0;
}
