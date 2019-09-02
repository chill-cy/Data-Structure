/*************************************************************************
	> File Name: 4.stack-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月02日 星期一 22时09分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int size, top;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (s == NULL) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s) {
    printf("Stack (%d) = [", s->top);
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 30
    srand(time(0));
    Stack *s = init(MAX_OP);
    int val, op;
    for (int i = 0; i < MAX_OP; i++) {
        val = rand() % 100;
        op = rand() % 3;
        switch(op) {
            case 0: 
            case 1: {
                printf("push %d to stack = %d\n", val, push(s, val));
            } break;
            case 2: {
                printf("pop %d to stack\n", top(s));
                pop(s);
            } break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
