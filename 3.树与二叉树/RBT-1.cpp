/*************************************************************************
	> File Name: RBT-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月21日 星期六 20时42分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, color;
    Node *lchild, *rchild;
} Node;

Node _NIL, * const *NIL = &_NIL;
__attribute__((constructor))

void init_NIL() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;
    return p;
}

int hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *__insert(Node *root, key) {
    Node *__insert()
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {

    return 0;
}
