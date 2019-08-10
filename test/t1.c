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

bool isSameTree (Node *p, Node *q) {
    if (p == NULL && q == NULL) {
        return true;
    } 
    if (!p || !q) return false;
    if (p->data - q->data) return false;
    bool flag1 = true, flag2 = true;
    flag1 = isSameTree(p->left, q->left);
    flag2 = isSameTree(p->right, q->right);
    return flag1 && flag2;
}

bool isSameTree2 (Node *p, Node *q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (!p || !q) return false;
    if (p->data - q->data) return false;
    return isSameTree2(p->left, q->right) && isSameTree2(p->right, q->left);
}

bool isSymmetric(Node *root) {
    if (root == NULL) return true;
    return isSameTree2(root->left, root->right);
}

Node *reverse(Node *p, Node *q) {
    int val = p->left->data;
    p->left->data = p->right->data;
    p->right->data = val;
    return reverse(p, q);
}

Node *invertTree(Node *root) {
    if (root == NULL) return NULL;
    int val = root->left->data;
    root->left->data = root->right->data;
    root->right->data = val;
    invertTree(root->left); 
    invertTree(root->right);
    return root; 
}

Node *__lowestCommonAncestor(Node *root, Node *p, Node *q) {
    if (p->data == root->data) return p;
    if (q->data == root->data) return q;
    if (p->data < root->data && q->data > root->data) return root;
    if (p->data < root->data) {
        __lowestCommonAncestor(root->left, p, q);
    } 
    if (p->data > root->data) {
        __lowestCommonAncestor(root->right, p, q);
    }
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q) {
    if (root == NULL) return NULL;
    if (p->data == q->data) return root;
    if (p->data > q->data) {
        Node *temp = p;
        p = q;
        q = temp;
    }
    return __lowestCommonAncestor(root, p, q);
}

//完全对称
/*bool isSymmetric(Node *root) {
    if (root->left == NULL && root->right == NULL) return true;
    if (!root->left || !root->right) return false;
    if (root->left->data - root->right->data) return false;
    return isSymmetric(root->left) && isSymmetric(root->right);
}
*/

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

    Node *p, *q;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (i == 2) p = tree->root;
        if (i == 4) q = tree->root;
        tree->root = insert(tree->root, val);
    }

    output(tree->root);
    
    printf("\n");
    /*int ans = 0;
    maxdeep(tree->root, 1, &ans);
    printf("%d\n", ans);
    printf("%d\n", mindeep(tree->root));
    if (PathSum(tree->root, 135)) {
        printf("success\n");
    } else {
        printf("false\n");
    }
    
    Tree *tree2 = initTree();

    for (int i = 0; i < n; i++) {
        int val2;
        scanf("%d", &val2);
        tree2->root = insert(tree2->root, val2);
    }

    if (isSameTree(tree->root, tree2->root)) {
        printf("OK\n");
    } else {
        printf("NO\n");
    }

    if (isSymmetric(tree->root)) {
        printf("Symmetric\n");
    } else {
        printf("no Symmetric\n");
    }

    //Tree *tree3 = initTree();
    //tree3->root = invertTree(tree->root);
    //output(tree3->root);
    */
    Node *lowest = lowestCommonAncestor(tree->root, p, q);
    printf("%d\n", lowest->data);

    return 0;
}
