/*************************************************************************
	> File Name: 18.RBT-11.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 00时34分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node _NIL, *NIL = &_NIL;
__attribute__((constructor))
void init() {
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild, NIL->rchild;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return NIL;
}

Node *_erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key < key) root->rchild = _erase(root->rchild, key);
    else if (root->key > key) root->lchild = erase(root->lchild, key);
    else {
        if (root->lchild == NIL && root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild->color = root->lchild->lchild;
        }
    }
}

Node *erase(Node *root, int key) {
    root = _erase(root, key);
    root->color = BLACK;
    return root;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
        goto insert_end;
    } 
    if (root->lchild->color == RED) {
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!has_red_child(root->rchild))  return root;
        if (root->rchild->lchild->color == RED) {
            root->lchild = right_rotate(root);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = RED;
    root->lchild->color = root->rchild->color;
    return root;
}

Node *_insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = _insert(root->rchild, key);
    else root->lchild = _insert(root->lchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = _insert(root, key);
    root->color = BLACK;
    return root;
}

int main() {
    return 0;
}
