/*************************************************************************
	> File Name: 7.HZOJ-237.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 07:10:04 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[10];
int vis[10] = {0};
void f(int, int);
void print_one_arr(int i);

int main()
{
    int n; 
    cin >> n;
    f(0, n);
    return 0;
}

void f(int i, int n)
{
    if (i == n)
    {
        print_one_arr(i);
        return ;
    }
    for (int k = 1; k <= n ; ++k)
    {
        if (vis[k]) continue;
        arr[i] = k;
        vis[k] = 1;
        f(i + 1, n);
        vis[k] = 0;
    }
    return ;
}
void print_one_arr(int i)
{
    for (int j = 0; j < i; ++j)
    {
        if (j) cout << " ";
        cout << arr[j];
    }
    cout << endl;
    return ;
}
