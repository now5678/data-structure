/*************************************************************************
	> File Name: 8.HZOJ-239.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 09:30:40 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

void  getPosition(long long n, long long s, long long &x, long long &y);


int main()
{
    long long t;
    scanf("%lld", &t);
    while(t--)
    {
        long long n, s, d;
        scanf("%lld%lld%lld", &n, &s, &d);
        long long x1, x2, y1, y2;
        getPosition(n, s, x1, y1);
        getPosition(n, d, x2, y2);
        printf("%.0lf\n", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) * 10);
    }
}
void  getPosition(long long n, long long s, long long &x, long long &y)
{
    if (n == 1)
    {
        if (s == 1)
        {
            x = 0;
            y = 0;
        }else if(s == 2)
        {
            x = 0;
            y = 1;
        }else if(s == 3)
        {
            x = 1;
            y = 1;
        }
        else{
            x = 1;
            y = 0;
        }
        return ;
    }
    long long line = 1LL << (n - 1);
    long long block = line * line;
    if (s <= block)
    {
        getPosition(n - 1, s, x, y);
        long long  t = y;
        y = x;
        x = t;
    }
    else if (s <= 2 * block)
    {
        getPosition(n - 1, s - block, x, y);
        y += line;
    }
    else if (s <= 3 * block)
    {
        getPosition(n - 1, s - 2 * block, x, y);
        x += line;
        y += line;
    }
    else if (s <= 4 * block)
    {
        getPosition(n - 1, s - 3 * block, x, y);
        int t = 2 * line - 1 - y;
        y = line - 1 - x;
        x = t;
    }
    return ;
}
