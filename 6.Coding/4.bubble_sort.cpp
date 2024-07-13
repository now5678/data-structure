/*************************************************************************
	> File Name: 4.bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Jul 2024 01:25:00 PM CST
 ************************************************************************/

#include "0.test.h"

void bubble_sort_v2(int * arr, int l, int r)
{
    int n = r - l;
    int flag;
    for (int i = n - 1; i > 0; --i)
    {
        flag = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (arr[j - 1] > arr[j]) {
                SWAP(arr[j - 1], arr[j])
                flag = 1;
            }
        }
        if (!flag){
            break;
        }
    }
}
void bubble_sort(int * arr, int l, int r)
{
    int n = r - l;
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (arr[j - 1] > arr[j]) {
                SWAP(arr[j - 1], arr[j])
            }
        }
    }
}
int main()
{
    int * arr = getRandArr(SMALLNUM);

    TEST(bubble_sort, arr, SMALLNUM);
    TEST(bubble_sort_v2, arr, SMALLNUM);
    return 0;
}
