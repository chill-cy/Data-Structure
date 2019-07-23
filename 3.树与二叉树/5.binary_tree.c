/*************************************************************************
	> File Name: 5.binary_tree.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 11时50分30秒
 ************************************************************************/

#include <stdio.h>
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
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->lchild = p->rchild = NULL;
    return p;
} 

Tree *getNewNode() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->n = 0;
    tree->root = NULL;
    return tree;
}

void clearNode() {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clearTree() {
    clearNode(tree->root);
    free(tree);
    return ;
}


void outputNode(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->val);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");

}

Node *insertNode(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->val == val) return root;
    if (root->val > val) root->lchild = insertNode(root->lchild, val);
    else root->rchild = insertNode(root->rchild, val);
    return root;
}

void insert(Tree *tree, int val) {
    int 
    tree->val = val;
}

Tree *build {
    
}

void outputTree(Tree *tree) {mZ    printf("tree(%d) = ")

}

void 
void preorder(Tree *tree) {
    printf("preorder : ");
    preorderNode(tree->root);
}

int main() {
    srand(time(0));
    Tree *tree = getNewNode();
    for (int i = 0; i < 10; i++) {
        int val = rand()
    }
}
