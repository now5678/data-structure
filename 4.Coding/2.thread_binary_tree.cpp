/*************************************************************************
	> File Name: 2.thread_binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jul 2024 06:59:17 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node 
{
    int value, ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node * getNewNode(int value)
{
    Node * n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->ltag = n->rtag = 0;
    n->lchild = n->rchild = NULL;
    return n;
}

Node *insert(Node * root, int value)
{
    if (root == NULL) 
    {
        root = getNewNode(value);
        return root;
    }
    if (rand() % 2)
    {
        root->lchild = insert(root->lchild, value);
    }else{
        root->rchild = insert(root->rchild, value);
    }
    return root;
}

Node * pre = NULL;

void __thread_inordered(Node * root)
{
    if (root == NULL) return;
    if (root->ltag == 0) __thread_inordered(root->lchild);
    if (root->lchild == NULL)
    {
        root->lchild = pre;
        root->ltag = 1;
    }
    if (pre && pre->rchild == NULL)
    {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;

    if (root->rtag == 0) __thread_inordered(root->rchild);
}

void thread_inordered(Node * root)
{
    __thread_inordered(root);
    pre->rtag = 1;
    return ;
}

void clearTree(Node * root)
{
    if (root == NULL) return ;
    clearTree(root->lchild);
    clearTree(root->rchild);
    free(root);
    return ;
}
Node * firstNode = NULL;

void inorder(Node * root)
{
    if (root == NULL) return ;
    if (root->ltag == 0) inorder(root->lchild);
    if (firstNode == NULL) firstNode = root;
    printf("%3d", root->value);
    if (root->rtag == 0) inorder(root->rchild);
    return ;
}

Node * getNextNode(Node * root)
{
    if (root->rtag) return root->rchild;
    root = root->rchild;
    while(root->ltag != 1 && root->lchild) root = root->lchild;
    return root;
}

int main()
{
    srand(0);
    Node * root = NULL;
    for (int i = 0; i < 20; ++i)
    {
        root = insert(root, rand() % 100);
    }

    inorder(root);
    printf("\n");
    thread_inordered(root);
    while(firstNode)
    {
        printf("%3d", firstNode->value);
        firstNode = getNextNode(firstNode);
    }
    printf("\n");
    return 0;
}
