/*************************************************************************
	> File Name: 3.set_usage.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Jul 2024 08:48:32 AM CST
 ************************************************************************/
#include <set>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

void test01()
{
    set<int> s;
    for (int i = 0; i < 10; i++)
    {
        int value = rand() % 100;
        s.insert(value);
        printf("insert %d into set \n", value);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        printf("%3d", *it);
    }
    printf("\n");
    for (int i:s)
    {
        printf("%3d", i);
    }
    printf("\n");

}



int main()
{
    srand(time(0));
    test01();
    return 0;
}
