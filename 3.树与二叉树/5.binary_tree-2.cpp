/*************************************************************************
	> File Name: 5.binary_tree-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月06日 星期五 16时23分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->n = 0;
    tree->root = NULL;
    return tree;
}

Node *insertNode (Node *root, int val, int *ret) {
    if (root == NULL) {
        *ret = 1;
        return getNewNode(val);
    }
    if (root->data == val) return root;
    if (root->data > val) root->lchild = insertNode(root->lchild, val, ret);
    else root->rchild = insertNode(root->rchild, val, ret);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}


void clearNode (Node *node) {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clearTree(Tree *tree) {
    clearNode(tree->root);
    free(tree);
    return ;
}

void outputNode (Node *root) {
    if (root == NULL) return;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(", ");
    outputNode(root->rchild);
    printf(")");
    return ;
}

void outputTree(Tree *tree) {
    printf("tree(%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;   
}

void preorderNode(Node *node) {
    if (node == NULL) return ;
    printf(" %d", node->data);
    preorderNode(node->lchild);
    preorderNode(node->rchild);
    return ;
}

void preorder(Tree *tree) {
    printf("preorder : ");
    preorderNode(tree->root);
    printf("\n");
}

void inorderNode(Node *node) {
    if (node == NULL) return ;
    inorderNode(node->lchild);
    printf(" %d", node->data);
    inorderNode(node->rchild);
    return ;
}

void inorder(Tree *tree) {
    printf("inorder : ");
    inorderNode(tree->root);
    printf("\n");
}


void postorderNode(Node *node) {
    if (node == NULL) return ;
    postorderNode(node->lchild);
    postorderNode(node->rchild);
    printf(" %d", node->data);
    return ;
}

void postorder(Tree *tree) {
    printf("postorder : ");
    postorderNode(tree->root);
    printf("\n");
}

int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        insert(tree, val);
        outputTree(tree);
    }
    preorder(tree);
    outputTree(tree);
    inorder(tree);
    outputTree(tree);
    postorder(tree);
    outputTree(tree);
    clearTree(tree);
    return 0;
}
