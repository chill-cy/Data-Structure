/*************************************************************************
	> File Name: 4.stack-4.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月04日 星期三 12时13分57秒
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
    s->top = -1;
    s->size = n;
}

int empty(Stack *s) {
    return s->top == -1;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int top(Stack *s) {
    if (empty(s)) return 0;
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
    s->top--;
    return 1;
}

void output(Stack *s) {
    printf("Stack (%d) = [", s->top + 1);
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_N 20
    srand(time(0));
    Stack *s = init(MAX_N);
    for (int i = 0; i < 20; i++) {
        int val = rand() % 100, op = rand() % 2;
        switch(op) {
            case 0: {
                printf("push %d to stack = %d\n", val, push(s, val));
            } break;
            case 1: {
                printf("pop item %d from stack\n", top(s));
                pop(s);
            } break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
