/*************************************************************************
	> File Name: 4.haffman.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Jul 2024 06:39:29 AM CST
 *************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Num 26

typedef struct Node{
    char ch;
    int fre;
    struct Node * lchild, *rchild;
} Node;

Node * getNewNode(char ch, int fre)
{
    Node * n = (Node *)malloc(sizeof(Node));
    n->lchild = n->rchild = NULL;
    n->ch = ch;
    n->fre = fre;
    return n;
}

Node * getMinNode(Node ** arr, int n)
{
    int ind = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[ind]->fre < arr[i]->fre)
        {
            Node * tmp = arr[ind];
            arr[ind] = arr[i];
            arr[i] = tmp;
        }
        ind = i;
    }
    return arr[ind];
}


Node * haffman(Node ** arr, int n)
{
    Node * p, * q, * tmp;
    for (int i = 1; i < n; ++i)
    {
        p = getMinNode(arr, n - i + 1);
        q = getMinNode(arr, n - i);
        tmp = getNewNode(' ', p->fre + q->fre);
        tmp->lchild = p;
        tmp->rchild = q;
        arr[n - i - 1] = tmp;
    }
    return arr[0];
}



void dehaffman(Node * root, char *buff, int len)
{
    if (root->lchild  == NULL && root->rchild == NULL)
    {
        printf("%c : %s\n", root->ch, buff);
        return ;
    }
    if (root->lchild)
    {
        buff[len] = '0';
        dehaffman(root->lchild, buff, len + 1);
    }
    if (root->rchild)
    {
        buff[len] = '1';
        dehaffman(root->rchild, buff, len + 1);
    }
    buff[len] = '\0';
}

int main()
{
    int n, fre, top = -1;
    char ch;
    scanf("%d", &n);
    Node ** arr = (Node **)malloc(sizeof(Node *) * n);

    for (int i = 0; i < n; ++i)
    {
        getchar();
        scanf("%c %d", &ch, &fre);
        arr[++top] = getNewNode(ch, fre);
    }

    Node * root = haffman(arr, top);
    char buff[20], len = 0;
    memset(buff, 0, 20);
    dehaffman(root, buff, len);

    return 0;
}
