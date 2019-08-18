/*************************************************************************
	> File Name: test.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月18日 星期日 23时16分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;\
    b = __temp;\
}

typedef struct Heap {
    long long *data;
    int size, cnt;
} Heap;

Heap *init(int n) {
    Heap *p = (Heap *)malloc(sizeof(Heap));
    p->data = (long long *)malloc(sizeof(long long) * (n + 1));
    p->size = n + 1;
    return p;
}

void clear(Heap *p) {
    if (p == NULL) return ;
    free(p->data);
    free(p);
    return ;
}

int push(Heap *p, long long val) {
    if (p == NULL) return 0;
    p->cnt++;
    p->data[p->cnt] = val;
    int ind = p->cnt;
    while (ind >> 1 >= 1) {
        if (p->data[ind] < p->data[ind >> 1]) {
            swap(p->data[ind], p->data[ind >> 1]);
            ind >>= 1;
        } else {
            break;
        }
    }
    return 1;
}

int pop(Heap *p) {
    if (p == NULL) return 0;
    if (p->cnt == 0) return 0;
    p->data[1] = p->data[p->cnt];
    p->cnt--;
    int ind = 1;
    while (ind << 1 <= p->cnt) {
        int tmp = ind, l = ind << 1, r = ind << 1 | 1;
        if (p->data[l] < p->data[tmp]) tmp = l;
        if (r <= p->cnt && p->data[r] < p->data[tmp]) tmp = r;
        if (tmp == ind) break;
        swap(p->data[tmp], p->data[ind]);
        ind = tmp;
    }
    return 1;
}

int nthUglyNumber(int n){
    Heap *p = init(n * 3);
    push(p, 1);
    long long val;
    while (n--) {
        val = p->data[1];
        pop(p);
        if (val % 5 == 0) {
            push(p, val * 5);
        } else if (val % 3 == 0) {
            push(p, val * 3);
            push(p, val * 5);
        } else {
            push(p, val * 2);
            push(p, val * 3);
            push(p, val * 5);
        }
    }
    clear(p);
    return val;
}


int main() {
    int n;
    cin >> n;
    cout << nthUglyNumber(n) << endl;
}
