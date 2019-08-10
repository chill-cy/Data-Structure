/*************************************************************************
	> File Name: 7.thread.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月07日 星期三 18时34分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int key;
    int ltarg, rtarg;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = key;
    p->ltarg = p->rtarg = 0;
    return p;
}

Node *insert (Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    if (root->ltarg == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->rtarg == NORMAL) inorder(root->rchild);
    return ;
}

void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltarg = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtarg = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltarg == NORMAL) clear(root->lchild);
    if (root->rtarg == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

Node *leftMost(Node *p) {
    while(p && p->ltarg == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output(Node *root) {
    Node *p = leftMost(root);//指向当前结点后继
    while (p) {
        printf("%d ", p->key);
        if (p->rtarg == THREAD) {
            p = p->rchild;
        } else {
            p = leftMost(p->rchild);
        }
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for(int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    inorder(root), printf("\n");
    output(root);
    clear(root);
    return 0;
}
