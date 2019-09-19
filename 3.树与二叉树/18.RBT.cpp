/*************************************************************************
	> File Name: 18.RBT.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月19日 星期四 19时21分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, color; 
    struct Node *lchild, *rchild;
} Node;

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED_COLOR && root->rchild->color == RED_COLOR) {
        root->color = RED_COLOR;
        root->lchild->color = root->rchild->color = BLACK_COLOR;
        return root;
    }
    if (has_red_child(root->lchild) && root->lchild->color == RED_COLOR) {
        if (root->lchild->rchild->color == RED_COLOR) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (has_red_child(root->rchild) && root->rchild->color == RED_COLOR) {
        if (root->rchild->lchild->color == RED_COLOR) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    } else goto insert_end;
    root->color = RED_COLOR;
    root->lchild->color = root->rchild->color = BLACK_COLOR;
insert_end;
    return root;
}

Node *__insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->key == val) return root;
    if (root->key < val) root->rchild = __insert(root->rchild, val);
    else root->lchild = __insert(root->rchild, val);
    return insert_maintain(root);
}

Node *insert(Node *root, int val) {
    root = __insert(root, val);
    root->color = BLACK_COLOR;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK && temp = temp->rchild) {
        root
    }
}

int main() {
    
    return 0;
}
