/*************************************************************************
	> File Name: TreadBinaryTree.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月12日 星期一 21时36mZ*************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;\
    b = __temp;\
}

typedef struct Heap{
    int *data;
    int size, cnt;
} Heap;

Heap *init(int n) {
    Heap *q = (Heap *)malloc(sizeof(Heap));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int empty(Heap *q) {
    return q->cnt == 0; 
}

int top(Heap *q) {
    return q->data[1];
}

int expand(Heap *q) {
    q->size *= 2;
    q->data = (int *)realloc(q->data, sizeof(int) * (q->size));
    return 1;
}

int push(Heap *q, int val) {
    if (q == NULL) return 0;
    if (q->size == q->cnt) expand(q);
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1) {
        if (q->data[ind] < q->data[ind >> 1]) {
            swap(q->data[ind], q->data[ind >> 1]);
            ind >>= 1;
        } else {
            break;
        }
    }
    return 1;
}

int pop(Heap *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt];
    q->cnt -= 1;
    int ind = 1;
    while(ind << 1 <= q->cnt){
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[temp] > q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] > q->data[r]) temp = r;
        if (temp == ind) break;
        swap(q->data[temp], q->data[ind]);
        ind = temp;
    }
    return 1;
}

int clean(Heap *q) {
    free(q->data);
    free(q);
    return 1;
}

int main() {
    srand(time(0));
    int n;
    scanf("%d", &n);
    printf("push start\n");
    Heap *q = init(n);
    printf("push start\n");
    for (int i = 1; i <= n; i++) {
        int val;
        val = rand() % 100;
        push(q, val);
    }
    printf("push over\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("pop over\n");
    printf("\n");
    clean(q);
    return 0;
}
