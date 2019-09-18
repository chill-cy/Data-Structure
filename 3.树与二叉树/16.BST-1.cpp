/*************************************************************************
	> File Name: 16.BST-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月17日 星期二 19时29分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int *lchild, *rchild;
} Node;

Node *getNewNode (int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return root;
}

int main() {

    return 0;
}
