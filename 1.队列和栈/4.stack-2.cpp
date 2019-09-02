/*************************************************************************
	> File Name: 4.stack-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月02日 星期一 21时52分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
}

int empty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1== s->size) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

int top (Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

void output(Stack *s) {
    printf("stack (%d) = [", s->top + 1);
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 30
    Stack *s = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 100;
        switch(op) {
            case 0: {
                printf("push %d to stack = %d\n", val, push(s, val));
            } break;
            case 1: {
                printf("pop %d from stack\n", top(s));
                pop(s);
            } break;
        }
        output(s);
        printf("\n");
    }
    return 0;
}
