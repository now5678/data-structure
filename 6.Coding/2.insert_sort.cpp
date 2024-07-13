/*************************************************************************
	> File Name: 2.insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Jul 2024 08:44:33 PM CST
 ************************************************************************/

#include "0.test.h"

void insert_sort_v2(int * arr, int l, int r)
{
    for (int i = l + 1, I = l + 1; i < r; ++i)
    {
        int j = i;
        while(j >= I && arr[j] < arr[j - 1]) 
        {
            SWAP(arr[j], arr[j - 1]);
            --j;
        }
    }
    return ;
}

void insert_sort_v3(int * arr, int l, int r)
{
    for (int i = l + 1, I = l + 1; i < r; ++i)
    {
        int j = i + 1;
        int ind = i - 1;
        for (int z = i; z < r; ++z)
        {
            if (arr[ind] > arr[z]) ind = z;
        }
        if (ind != i - 1) SWAP(arr[i-1], arr[ind]);
        while(arr[j] < arr[j - 1]) 
        {
            SWAP(arr[j], arr[j - 1]);
            --j;
        }
    }
    return ;
}

void insert_sort(int * arr, int l, int r)
{
    for (int i = l + 1; i < r; ++i)
    {
        for (int j = i; j > l; --j)
        {
            if (arr[j] >= arr[j - 1]) break; 
            SWAP(arr[j], arr[j - 1]);
        }
    }
    return ;
}

void unsurpervised_insert_sort(int * arr, int l, int r)
{
    for (int i = l + 1; i < r; ++i)
    {
        int ind = i - 1;
        for (int z = i; z < r; ++z)
        {
            if (arr[ind] > arr[z]) ind = z;
        }
        if (ind != i - 1) SWAP(arr[i-1], arr[ind]);
        for (int j = i;; --j)
        {
            if (arr[j] >= arr[j - 1]) break; 
            SWAP(arr[j], arr[j - 1]);
        }
    }
    return ;
}


int main()
{
    int * arr = getRandArr(SMALLNUM);
    TEST(insert_sort, arr, SMALLNUM);
    TEST(unsurpervised_insert_sort, arr, SMALLNUM);
    TEST(insert_sort_v2, arr, SMALLNUM);
    TEST(insert_sort_v3, arr, SMALLNUM);
    free(arr);
    return 0;
}
