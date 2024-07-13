/*************************************************************************
	> File Name: 3.HZOJ-186.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 09:44:59 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

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
    for(int i = 0; i < n; )
    {
        i += arr[i];
        ++sum;
    }
    cout << sum << endl;
    return 0;

}
