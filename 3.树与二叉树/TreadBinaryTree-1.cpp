#include <stdio.h>
#include <iostream>

using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) {
        root->rchild = insert(root->rchild, key);
    } else {
        root->lchild = insert(root->lchild, key);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) inorder(root->rchild);
    return ;
}

Node *leftMost(Node *p) {
    if (p && p->ltag == NORMAL && p->lchild) {
        p = p->lchild;
    }
    return p;
}

void Thread_build(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    leftMost(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    } 
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    leftMost(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    leftMost(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    } 
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    leftMost(root->rchild);
    return ;
}

int main() {
    int val;
    srand(time(0));
    Node *root = NULL;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        val = rand() % 100;
        root = insert(root, val);
    }
    Thread_build(root);
    output(root);
    inorder(root), printf("\n");
    clear(root);
    return 0;
}
