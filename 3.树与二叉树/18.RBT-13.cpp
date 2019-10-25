/*************************************************************************
	> File Name: 18.RBT-13.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月25日 星期五 18时34分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->lchild = p->rchild = NULL;
    p->color = RED;
    return p;
}

Node *_insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    else if (root->key < key) root->rchild = _insert(root->rchild);
    else root->lchild = 
}

Node *insert(Node *root, int key) {
    root = insert(root, key);
    root->color = BLACK;
    return root;
}

int main() {
    int op, val;
    Node *root = NULL;
    while (cin >> op >> val) {
        switch(op) {
            case 0: root = insert(root, val);
            case 1: root = erase(root, val);
        }
        output(root);
    }
    return 0;
}
