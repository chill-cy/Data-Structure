/*************************************************************************
	> File Name: 287-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月13日 星期二 11时14分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Fruit {
    int *data;
    int cnt, size;
} Fruit;

Fruit *init(int n) {
    Fruit *q = (Fruit *)malloc(sizeof(Fruit));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int push(Fruit *q, int val) {
    if (q == NULL) return 0;
    if (q->size == q->cnt) return 0;
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

int empty(Fruit *q) {
    return q->cnt == 0;
}

int top(Fruit *q) {
    return q->data[1];
}

int pop(Fruit *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    int top_value = q->data[1];
    q->data[1] = q->data[q->cnt];
    q->cnt -= 1;
    int ind = 1;
    while (ind << 1 <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[temp] > q->data[l]) temp = l;
        if (r <= q->cnt && q->data[temp] > q->data[r]) temp = r;
        if (temp == ind) break;
        swap(q->data[temp], q->data[ind]);
        ind = temp;
    }
    return top_value;
}

int main() {
    int n, energy;
    scanf("%d", &n);
    Fruit *q = init(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &energy);
        push(q, energy);
    }

    int sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        int val1 = pop(q);
        int val2 = pop(q);
        sum += val1 + val2;
        push(q, val1 + val2);
    }
    printf("%d\n", sum);
    return 0;
}
