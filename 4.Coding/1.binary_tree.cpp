/*************************************************************************
	> File Name: 1.binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Jul 2024 09:40:50 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;
typedef struct Node
{
    int value;
    struct Node * lchild, * rchild;
} Node;


Node * getNode(int value)
{
    Node * n = (Node *)malloc(sizeof(Node));
    n->lchild = n->rchild = NULL;
    n->value = value;
    return n;
}


Node * insert(Node * root, int value)
{
    if (root == NULL)
    {
        root = getNode(value);
        return root;
    }
    if (rand() % 2)
    {
        root->lchild = insert(root->lchild, value);
        return root;
    }else{
        root->rchild = insert(root->rchild, value);
        return root;
    }

}

void bfs(Node * root)
{
    if (root == NULL) return ;
    queue<Node *> q;
    Node * p = root;
    int i = 0;
    while(p)
    {
        printf("%d\n", i++);
        printf("   %3d   \n", p->value);
        if (p->lchild) 
        {
            q.push(p->lchild);
            printf("%3d", p->lchild->value);
        }else{
            printf("   ");
        }
        printf("   ");
        if (p->rchild) 
        {
            q.push(p->rchild);
            printf("%3d", p->rchild->value);
        }
        printf("\n");
        p = q.front();
        q.pop();
    }

}

void clearTree(Node * root)
{
    if (root == NULL) return;
    clearTree(root->lchild);
    clearTree(root->rchild);
    free(root);
    return ;
}

void dfs(Node * root)
{
    static int i = 0;
    if (root == NULL) return;
    dfs(root->lchild);
    dfs(root->rchild);
    printf("%d\n", i++);
    printf("%3d\n", root->value);
    return ;
}

int main()
{
    srand(0);
    Node * root = NULL;
    for (int i = 0; i < 20; ++i)
    {
        int value = rand() % 100;
        root = insert(root, value);
    }

    bfs(root);
    printf("---------------------------\n");
    dfs(root);
    clearTree(root);
    return 0;
}
