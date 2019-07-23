/*************************************************************************
	> File Name: 6.build.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 10时28分44秒
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

typedef struct *initStack {
    int top, size;
    Node **data;
} Stack;

Stack *initStack (int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int emptyStack(Stack *s) {
    return s->top == -1;
}

int pushStack(Stack *s, Node *node) {
    if (s->top + 1 >= s->size) return ;
    s->data[++(s->top)] = node;
    return ;
}

void popStack(Stack *s) {
    if (emptyStack(s)) return ;
    --(s->top);
}

Node *topStack(Stack *s) {
    if (emptyStack(s)) return NULL;
    return s->data[s->top];
}

void clearStack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = val;
    return p;
}

Node *build(const char *str) {
    int len = strlen(str);
    Stack *s = initStack(len);
    int status = 0, k = 0;
    Node *p = NULL;
    while (str[0]) {
        printf("status = %d k = %d\n", status, k);
        switch (status[0]) {
            case 0: {
                if (str[0] <= '9' && str[0] >= '0') {
                    status = 1;
                } else if (str[0] == '(') {
                    status = 2;
                } else if (str[0] == ')') {
                    status = 4;
                } else {
                    str++;
                }
            } break;
            case 1: {
                if (p == NULL) {
                    p = getNewNode(0);
                    if (k == 0 && !emptyStack(s)) {
                        topStack(s)->rchild = p;
                    }
                }
                if (str[0] <= '9' && str[0] >= '0') {
                    p->key = p->key * 10 + str[0] - '0';
                    str++;
                } else {
                    status = 0;
                } 
            } break;
            case 2: {
                pushStack(s, p);
                k = 0;
                p = NULL;
                status = 0;
                str++;
            } break;
            case 3: {
                k = 1;
                p = NULL;
                status = 0;
                str++;
            } break;
            case 4: {
                p = topStack(s);
                popStack(s);
                status = 0;
                str++;
            } break;
        }
    }
    return p;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild), clear(node->rchild);
    free(node);
    return ;
}

void preorder(Node *root) {
    if (root == NULL) return ;
    clear(node->lchild), clear(node->rchild);
    free(node);
    return ;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    inorder(root->lchild);
    printf("%d ", root->key);
    inorder(root->rchild);
    return ;
}

int main() {
    char str[100];
    while (~scanf("%[^\n]s", str)) {
        getchar();
        printf("%s\n", str);
        Node *root = build(str);
        preorder(root), printf("\n");
        inorder(root), printf("\n");
    }
    return 0;
}
