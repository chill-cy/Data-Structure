/*************************************************************************
	> File Name: 7.thread-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月10日 星期二 16时31分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000
#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode (int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = p->rtag = NORMAL;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    return ;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    inorder(root->lchild);
    printf("%d ", root->key);
    inorder(root->rchild);
    return ;
}

Node *leftMost(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) {
        p = p->lchild;
    }
    return p;
}

void output(Node *root) {
    if (root == NULL) return ;
    Node *p = root;
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    while (p) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = leftMost(p->rchild);
        }
    }
    return ;
}

Node *insert(Node *root, int key) {
    if (root == NULL) {
        return getNewNode(key);
    }
    if (root->key == key) return root;
    if (root->key < key) {
        root->rchild = insert(root->rchild, key);
    } else {
        root->lchild = insert(root->lchild,key);
    }
    return root;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        insert(root, val);
    }
    inorder(root), printf("\n");
    output()
    clear(root);
    return 0;
}
