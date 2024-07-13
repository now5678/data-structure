/*************************************************************************
	> File Name: 4.HZOJ-186.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 09:55:07 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int epoch(int , const int &, const int * );


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int dis = 0;
    sum = epoch(dis, n, arr);
    cout << sum << endl;
    return 0;

}

int epoch(int dis, const int &n, const int * arr)
{
    if (dis > n - 1)
    {
        return 0;
    }
    dis += arr[dis];
    return 1 + epoch(dis, n, arr);
}
