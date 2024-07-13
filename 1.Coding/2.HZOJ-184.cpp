/*************************************************************************
	> File Name: 2.HZOJ-184.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 09:31:56 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int last(int);

int main()
{
    int n;
    cin >> n;
    int sum = last(n);
    cout << sum << endl;
    return 0;
}

int last(int n)
{
   if (n == 1)
    {
        return 1;
    }
    return (last(n - 1) + 1) * 2;
}
