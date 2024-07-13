/*************************************************************************
	> File Name: 5.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Jul 2024 01:41:48 PM CST
 ************************************************************************/

#include "0.test.h"

void quick_sort(int * arr, int l, int r)
{
    if ((r - l) <= 2)
    {
        if (r - l <= 1 ) return;
        if (arr[l] > arr[l + 1]) SWAP(arr[l], arr[l + 1]);
    }
    int low = l, high = r - 1, z = arr[l];
    while(low < high)
    {
        while(low < high && arr[high] >= z) --high;
        if (low < high) arr[low++] = arr[high];
        while(low < high && arr[low] <= z) ++low;
        if(low < high) arr[high--] = arr[low];
    }
    arr[low] = z;
    quick_sort(arr, l, low);
    quick_sort(arr, low + 1, r);
    return ;
}

int main()
{
    int * arr = getRandArr(BIGNUM);
    TEST(quick_sort, arr, BIGNUM);
    return 0;
}
