/*************************************************************************
	> File Name: 16.BST.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月17日 星期二 19时12分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) returnt getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *erase (Node *root, int key) {
    if (root == NULL) return root;
    if (root->key < key) root->rchild = erase(root->rchild, key);
    else if (root->key > key) root->lchild = erase(root->lchild, key);
    else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

Node __in_order(Node *root) {
    if (root == NULL) return ;
    __in_order(root->lchild);
    printf("%d", root->key);
    __in_order(root->rchild);
    return ;
}

Node in_order(Node *root) {
    printf("inorder output = ");
    __in_order(root);
    printf("\n");
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

int main() {
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 0: {
                root = insert(root, val);
            } break;
            case 1: {
                root = erase(root, val) ;
            } break;
        }
        in_order(root);
    }
    return 0;
}
