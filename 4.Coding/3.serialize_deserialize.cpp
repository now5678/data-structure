/*************************************************************************
	> File Name: 3.serialize_deserialize.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jul 2024 08:33:46 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MaxNum 5

typedef struct Node
{
    int key;
    struct Node * lchild, * rchild;
} Node;

Node * getNewNode(int key)
{
    Node * n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->lchild = n->rchild = NULL;
    return n;
}

Node * insert(Node * root, int key)
{
    if (root == NULL)
    {
        root = getNewNode(key);
        return root;
    }
    if (rand() % 2)
    {
        root->lchild = insert(root->lchild, key);
    }else{
        root->rchild = insert(root->rchild, key);
    }
    return root;
}

Node *getRandomTree(int n)
{
    Node * root = NULL; 
    for (int i = 0; i < n; ++i)
    {
       root = insert(root, rand() % 100);
    }
    return root;
}

char buff[256];
int len = 0;

void initBuff()
{
    memset(buff, 0, 256 * sizeof(char));
    len = 0;
}

void serialize(Node * root)
{
    if (root == NULL) return ;
    len += sprintf(buff + len, "%d", root->key);
    if (root->lchild || root->rchild)
    {
        len += sprintf(buff + len, "(");
    }
    if (root->lchild)
    {
        serialize(root->lchild);
    }
    if (root->rchild)
    {
        len += sprintf(buff + len, ",");
        serialize(root->rchild);
        len += sprintf(buff + len, ")");
    }

}

Node * deserialize(char * buff, int len)
{
    if (buff == NULL) return NULL;
    Node ** stk = (Node **)malloc(sizeof(Node *) * MaxNum);
    Node * p = NULL, * root;
    int top = -1, scode = 0, flag = 0;
    for (int i = 0; i < len;)
    {
        switch(scode)
        {
            case 0:
            {
                if (buff[i] >= '0' && buff[i] <= '9')
                {
                    scode = 1;
                }else if (buff[i] == '(')
                {
                    scode = 2;
                }else if (buff[i] == ',')
                {
                    scode = 3;
                }else{
                    scode = 4;
                }
            } break;
            case 1:
            {
                int num = 0;
                while(buff[i] >= '0' && buff[i] <= '9')
                {
                    num = num * 10 + buff[i++] - '0';
                }
                p = getNewNode(num);
                if (top >= 0 && flag == 0)
                {
                    stk[top]->lchild = p;
                }else if (top >= 0 && flag == 1)
                {
                    stk[top]->rchild = p;
                }
                scode = 0;
            } break;
            case 2:
            {
                stk[++top] = p;
                ++i;
                flag = 0;
                scode = 0;
            } break;
            case 3:
            {
                flag = 1;
                i++;
                scode = 0;
            } break;
            case 4:
            {
                root = stk[top--];
                i++;
                scode = 0;
            }
        }
    }
    return root;
}

void output(Node * root)
{
    if (root == NULL) return ;
    printf("%3d", root->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

void output_in(Node * root)
{
    if (root == NULL) return;
    output_in(root->lchild);
    printf("%3d", root->key);
    output_in(root->rchild);
    return ;
}

void clear(Node * root)
{
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}


int main()
{
    srand(0);
    Node * root = getRandomTree(MaxNum);
    output(root);
    printf("\n");
    output_in(root);
    printf("\n");
    initBuff();
    serialize(root);
    printf("%s\n", buff);
    output(deserialize(buff, len));
    clear(root);
    return 0;
}
