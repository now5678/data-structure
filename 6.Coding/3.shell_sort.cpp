/*************************************************************************
	> File Name: 3.shell_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Jul 2024 12:27:10 PM CST
 ************************************************************************/

#include "0.test.h"

void insert_sort(int * arr, int l, int r, int step)
{
    for (int i = l + step, I = l + step; i < r; i += step)
    {
        int j = i;
        while(j >= I && arr[j] < arr[j - step]) 
        {
            SWAP(arr[j], arr[j - step]);
            --j;
        }
    }
    return ;
}

void shell_sort(int *arr, int l, int r)
{
    int step = (r - 1);
    do{
        step = step/2 > 0 ? step/2 : 1;
        for (int i = l; i < step; ++i)
        {
            insert_sort(arr, l, r, step);
        }
    }while(step != 1);
    return ;
}

int main()
{
    int *arr = getRandArr(BIGNUM);
    TEST(shell_sort, arr, BIGNUM);
    free(arr);
    return 0;
}
