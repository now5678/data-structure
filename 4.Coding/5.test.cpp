/*************************************************************************
	> File Name: 5.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Jul 2024 06:41:29 AM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    printf("26\n");
    srand(time(0));
    for (int i = 0; i < 26; ++i)
    {
        printf("%c %d\n", 'a' + i, rand() % 10000);
    }

    return 0;
}
