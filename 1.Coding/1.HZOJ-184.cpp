/*************************************************************************
	> File Name: 1.HZOJ-184.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 09:22:59 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main()
{
    int n;
    cin >> n;
    int sum = 1;
    for (int i = 1; i < n; ++i)
    {
        sum = (sum + 1) * 2;
    }
    cout << sum << endl;
    return 0;
}

