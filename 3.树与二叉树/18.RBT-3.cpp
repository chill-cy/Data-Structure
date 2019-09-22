/*************************************************************************
	> File Name: 18.RBT-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月22日 星期日 23时22分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

#define RED 0
#define BLACK 1
#define 
void init() {
    NIL->key = 0;
    NIL->lchild = NIL->rchild = NIL:
    NIL->color = BLACK;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL:
    return p;
}

int main() {

    return 0;
}
