/*************************************************************************
	> File Name: 3.queue-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月17日 星期三 14时11分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Queue {
    int *data;
    int head, tail;
    int length, count;
}

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizoof(int) * n);
    q->length = n;
    q->count = 0;
    q->head = q->tail = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->count == 0;
}

void push(Queue *q, int val) {
    if (q->count == q->length) return;
    q->data[(q->tail)++] = val;
    q->length = n;
    q->count = 0;
    q->head = q->tail = 0;
    return ;
}

