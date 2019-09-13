/*************************************************************************
	> File Name: 3.queue-7.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月04日 星期三 10时49分02秒
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
}

int empty(Queue *q) {
    if (q == NULL) return 0;
    return q->cnt == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->length) return 0;
    q->data[q->tail++] = val;
    if (q->tail == q->length) q->tail -= q->length;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->length) q->head -= q->length;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    printf("Queue (%d) = [", q->cnt);
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        int ind = (i + j) % q->length;
        printf(" %d", q->data[ind]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    int val, op;
    #define MAX_OP 30
    Queue *q = init(MAX_OP);
    srand(time(0));
    for (int i = 0; i < MAX_OP; i++) {
        val = rand() % 100, op = rand() % 2;
        switch (op) {
            case 0: {
                printf("push %d to queue = %d\n", val, push(q, val));
            } break;
            case 1: {
                printf ("pop item %d from queue\n", front(q));
                pop(q);
            } break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
