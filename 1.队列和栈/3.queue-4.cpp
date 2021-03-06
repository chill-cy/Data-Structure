/*************************************************************************
	> File Name: 3.queue-4.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月02日 星期一 20时26分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->cnt = 0;
    q->length = n;
    return q;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int push (Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->tail == q->length) return 0;
    q->data[q->tail++] = val;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    if (q == NULL) return ;
    printf("Queue = [");
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        int ind = (i + j) % q->length;
        printf(" %d", q->data[ind]);
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    Queue *q = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100, op = rand() % 2;
        switch(op) {
            case 0: {
                printf("push %d to queue = %d\n", val, push(q, val));
            } break;
            case 1: {
                printf("pop %d from queue\n", front(q));
                pop(q);
            } break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
