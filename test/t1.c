/*************************************************************************
	> File Name: t1.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月06日 星期二 21时37分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node *left, *right; 
}Node;

typedef struct Tree {
    Node *root;
}Tree;

Node *initNode (int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Tree *initTree() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node *insert(Node *tree, int val) {
    if (tree == NULL) {
        Node *p = initNode(val);
        return p;
    }
    if (val == tree->data) return tree;
    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else {
        tree->right = insert(tree->right, val);
    }
    return tree;
}

bool PathSum(Node *root, int sum) {
    if (root->left == NULL && root->right == NULL) {
        if (sum == root->data) return true;
        else return false;
    } 
    bool flag = false, flag2 = false;
    if (root->left) {
        sum -= root->data;
        flag = PathSum(root->left, sum);
    } 
    if (root->right) {
        sum -= root->data;
        flag2 = PathSum(root->right, sum);
    }
    if (flag == true || flag2 == true) return  true;
    return false;
}

int mindeep(Node *root) {
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int minl = 99999, minr = 99999;
    if (root->left) {
        minl = mindeep(root->left);
    }
    if (root->right) {
        minr = mindeep(root->right);
    }
    return minr > minl ? minl + 1 : minr + 1;
}

void maxdeep(Node *root, int deep, int *maxd) {
    if (root->left == NULL && root->right == NULL) {
        if(*maxd < deep) *maxd = deep;
        return ;
    }
    if (root->left) 
    maxdeep(root->left, deep + 1, maxd);
    if (root->right)
    maxdeep(root->right, deep + 1, maxd);
}
void output(Node *root) {
    if (root == NULL) return;
    printf("%d  ", root->data);
    fflush(stdout);
    output(root->left);
    output(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    Tree *tree = initTree();

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        tree->root = insert(tree->root, val);
    }

    output(tree->root);
    
    printf("\n");
    int ans = 0;
    maxdeep(tree->root, 1, &ans);
    printf("%d\n", ans);
    printf("%d\n", mindeep(tree->root));
    if (PathSum(tree->root, 135)) {
        printf("success\n");
    } else {
        printf("false\n");
    }
    return 0;
}
