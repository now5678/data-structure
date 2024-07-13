/*************************************************************************
	> File Name: 1.select_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Jul 2024 08:29:30 PM CST
 ************************************************************************/

#include "0.test.h"


void select_sort(int * arr, int l, int r)
{
    for (int i = l; i < r - 1; ++i)
    {
        int ind = i;
        for(int j = i + 1; j < r; ++j)
        {
            if (arr[j] < arr[ind]) ind = j;
        }
        SWAP(arr[i], arr[ind]);
    }
}

int main()
{
    int *arr = getRandArr(SMALLNUM);
    TEST(select_sort, arr, SMALLNUM);
    free(arr);
    return 0;
}
