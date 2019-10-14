/*************************************************************************
	> File Name: 284.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月27日 星期二 22时39分39秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 10000
struct Data {
    int val, day;
};

typedef struct Heap {
    struct Data *arr;
    int size, cnt;
} Heap;

bool cmp(const Data &a, const Data &b) {
    return a.day < b.day;
}

Heap *init(int n) {
    Heap *q = (Heap *)malloc(sizeof(Heap));
    q->arr = (struct Data *)malloc(sizeof(struct Data *) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int empty(Heap *q) {
    return q->cnt == 0;
}

int top (Heap *q) {
    return q->arr[1].val;
}

int push(Heap *q, struct Data material) {
    if (q == NULL) return 0;
    if (q->size == q->cnt) return 0;
    q->cnt += 1;
    q->arr[q->cnt].val = material.val;
    q->arr[q->cnt].day = material.day;
    int ind = q->cnt;
    while (ind >> 1) {
        if (q->arr[ind].val < q->arr[ind >> 1].val) {
            swap(q->arr[ind], q->arr[ind >> 1]);
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
    q->arr[1] = q->arr[q->cnt];
    q->cnt -= 1;
    int ind = 1;
    while (ind << 1 <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->arr[temp].val > q->arr[l].val) temp = l;
        if (r <= q->cnt && q->arr[temp].val > q->arr[r].val) temp = r;
        if (temp == ind) break;
        swap(q->arr[temp], q->arr[ind]);
        ind = temp;
    }
    return 1;
}

int clean(Heap *q) {
    free(q->arr);
    free(q);
}


int main() {
    int n;
    scanf("%d", &n);
    Heap *q = init(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &q->arr[i].val, &q->arr[i].day);
    }
    sort(q->arr + 1, q->arr + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (q->arr[i].day > q->cnt) {
            push(q, q->arr[i]);
        } else if (q->arr[i].val > top(q)) {
            pop(q);
            push(q, q->arr[i]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= q->cnt; i++) {
        sum += q->arr[i].val;
    }
    printf("%d\n", sum);
    return 0;
}

