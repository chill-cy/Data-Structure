/*************************************************************************
	> File Name: 7.thread-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月10日 星期二 15时53分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode (int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = key;
    p->ltag = p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) inorder(root->rchild);
    return ;
}

void build_thread(Node *root) {
    if (root == NULL) return;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}


void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

Node *leftMost(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output(Node *root) {
    Node *p = root;
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    while (p) {
        printf("%d\n", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = p->rchild;
            while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
        }
    }
    return ;
}

int main() {
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    inorder(root), printf("\n");
    output(root);
    clear(root);
    return 0;
}
