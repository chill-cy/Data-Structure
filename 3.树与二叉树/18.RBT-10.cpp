/*************************************************************************
	> File Name: 18.RBT-10.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月29日 星期日 11时45分24秒
 ************************************************************************/

#include <stdio.h>

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

Node *_erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key < key) root->rchild = _erase(root->rchild, key);
    else if (root->key > key) root->lchild = _erase(root->lchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root)
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
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = RED;
    root->lchild->color = BLACK;
    root->rchild->color = BLACK;
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return insert_maintain(root);
}

int main() {

    return 0;
}
