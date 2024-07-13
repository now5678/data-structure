/*************************************************************************
	> File Name: 5.HZOJ-235.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 02:54:02 PM CST
 ************************************************************************/
 #include<iostream>
using namespace std;

int arr[10];

void f(int, int, int);
void print_one_arr(int i);

int main()
{
    int n;
    cin >> n;
    f(0, 1, n);
    return 0;
}

void f(int i, int j, int n)
{
    if (j > n)
    {
        return ;
    }
    for (int k = j; k <= n; ++k)
    {
        arr[i] = k;
        print_one_arr(i);
        f(i + 1, k + 1, n);
    }
    return ;
}

void print_one_arr(int i)
{
    for (int k = 0; k <= i; ++k)
    {
        if (k != 0) cout << " ";
        cout << arr[k];
    }
    cout << endl;
    return;
}
