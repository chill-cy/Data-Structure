/*************************************************************************
	> File Name: 18.RBT-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月20日 星期五 11时50分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;

#define NIL (&__NIL)
#define RED_COLOR 0
#define 
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = BLACK_COLOR;
    NIL->lchild = NIL->rchild = NIL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED_COLOR;
    p->lchild = p->rchild = NIL;
    return p;
}

Node *insert(Node *root, int val) {                             
    if (root == NIL) return getNewNode(val);
    if (root->key == val) root->rchild = insert(root->rchild, val);
    if (root->key < key) root->rchild = insert(root->rchild, )
}

void clear(Node *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}


int main() {

    return 0;
}
