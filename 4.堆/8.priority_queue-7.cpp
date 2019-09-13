/*************************************************************************
	> File Name: 8.priority_queue-7.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月11日 星期三 20时40分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int top(priority_queue *q) {
    return q->data[1];
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int push(priority_queue *q, int val) {
    if (q->cnt == q->size) return 0;
    q->cnt++;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while ((ind >> 1) && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt];
    q->cnt--;
    int ind = 1;
    while((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (ind == temp) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;

}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    #define MAX_OP 20
    priority_queue *q = init(MAX_OP);
    srand(time(0));
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(q, val);
    }
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    return 0;
}
