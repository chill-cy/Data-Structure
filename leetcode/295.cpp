/*************************************************************************
	> File Name: 295.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月12日 星期一 18时10分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Heap {
    int *data;
    int n, size;
} Heap;

void expandHeap(Heap *h) {
    h->data = realloc(h->data, 2 * h->size * sizeof(int));
    h->size *= 2;
    return ;
}

#define swap(a, b) { \
    __typeof(a) __temp = a;\
    a = b, b = __temp; \
}

#define pushHeap(h, val, comp) { \
    if (h->size == h->n + 1) {\
       expandHeap(h);\
    }
}
