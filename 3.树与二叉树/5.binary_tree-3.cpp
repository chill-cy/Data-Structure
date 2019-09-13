/*************************************************************************
	> File Name: 5.binary_tree-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月06日 星期五 17时14分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

void clearNode(Node *root) {
    if (root == NULL) return ;
    clearNode(root->lchild);
    clearNode(root->rchild);
    free(root);
    return ;
}

void clearTree(Tree *tree) {
    if (tree == NULL) return ;
    clearTree(tree->root);
    free(tree);
    return ;
}

Node *insertNode(Tree *root, int val) {
    if (root == NULL) {
        return getNewNode(val);
    }
    if (root->val > val) root->lchild = insertNode(root->lchild, val);
    else root->rchild = insertNode(root->rchild, val);
    return root;
}

void output(Tree *root, &cnt) {
    if (root == NULL) return ;
    printf("%d", root->val);
    cnt += 1;
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    if (root->lchild) output(root->lchild);
    printf(", ");
    if (root->rchild) output(root->rchild);
    printf(")");
    printf("\n");
}

void preorderNode(Node *root) {
    preorderNode(root->lchild);
    preorderNode(root->rchild);
    printf(" %d", root->val);
    return ;
}

void inorderNode(Node *root) {
    inorderNode(root->lchild);
    printf(" %d", root->val);
    inorderNode(root->rchild);
    return ;
}

void postorderNode(Node *root) {
    postorderNode(root->lchild);
    postorderNode(root->rchild);
    printf(" %d", root->val);
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    Tree *tree = getNewTree();
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        insertNode(tree, val);
        output(tree->root);
    }
    preorderNode(tree->root);
    inorderNode(tree->root);
    postorderNode(tree->root);
    return 0;
}
