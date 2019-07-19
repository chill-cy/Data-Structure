/*************************************************************************
	> File Name: 7.stack.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 14时58分14秒
 ************************************************************************/

#include <stdio.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

typedef struct Node {
    int **data;
    int top, size;
} stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s == NULL || s->top == -1;
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top -= 1;
    return ;
}

void push(Stack *s, Node *node) {
    if (s->top + 1 >= s->size) return;
    s->data[++(s->top)] = node;
    return ;
}

void clearStack(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
}
int main() {
    srand(time(0));
    Stack *s1 = initStack(len);
    Stack *s2 = initStack(len);
    while (str[0]) {
        
        if (s->data[s->top] >  )
    }
    return 0;
}
