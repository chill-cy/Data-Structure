 
/*************************************************************************
   > File Name: 5.binary_tree.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 日  7/21 15:48:09 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct N_ode {
    int val;
    struct N_ode *lchild, *rchild;
} N_ode;

N_ode *getNewNode(int val) {
    N_ode *p = (N_ode *)malloc(sizeof(N_ode));
    p->val = val;
    p->lchild = p->rchild = NULL;
    return p;
}


N_ode *insertNode(N_ode *root, int val) {
    if (root == NULL) {
        return getNewNode(val);
    }
    if (root->val == val) return root;
    if (root->val > val) root->lchild = insertNode(root->lchild, val);
    else root->rchild = insertNode(root->rchild, val);
    return root;
}


void clearNode(N_ode *node) {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void outputNode(N_ode *root) {
    if (root == NULL) return ;
    printf("%d", root->val);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}

void preorderNode(N_ode *node) {
    if (node == NULL) return ;
    printf(" %d", node->val);
    preorderNode(node->lchild);
    preorderNode(node->rchild);
    return ;
}


void inorderNode(N_ode *node) {
    if (node == NULL) return ;
    inorderNode(node->lchild);
    printf(" %d", node->val);
    inorderNode(node->rchild);
    return ;
}


void postorderNode(N_ode *node) {
    if (node == NULL) return ;
    postorderNode(node->lchild);
    postorderNode(node->rchild);
    printf(" %d", node->val);
    return ;
}

int main() {
    srand(time(0));
    N_ode *tree = NULL;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        tree = insertNode(tree, val);
        outputNode(tree);
        printf("\n");
    }
    preorderNode(tree);
    printf("\n");
    inorderNode(tree);
    printf("\n");
    postorderNode(tree);
    printf("\n");
    clearNode(tree);
    return 0;
}

