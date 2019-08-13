/*************************************************************************
	> File Name: 703.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月11日 星期日 21时57分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = temp;\
}

typedef struct {
    int *data;
    int cnt, size;
} KthLargest;
//建立小根堆 
void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] < arr[temp]) temp = l;
        if (r <= n && arr[temp] < arr[temp]) temp = r;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void upUpdate(int *arr, int ind) {
    while (ind >> 1) {
        if (arr[ind] >= arr[ind >> 1]) break;
        swap(arr[ind], arr[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

int KthLargestAdd(KthLargest* , int);
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *p = (KthLargest *)malloc(sizeof(KthLargest));
    p->data = (int *)malloc(sizeof(int) * (k + 1));
    p->size = k;
    p->cnt = k - 1;
    memcpy(p->data + 1, nums, sizeof(int) * (k - 1));
    for (int i = (k - 1) >> 1; i >= 1; --i) {
        downUpdate(p->data, k - 1, i);
    }
    for (int i = k - 1; i < numsSize; i++) {
        KthLargestAdd(p, nums[i]);
    }
    return p;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->cnt == obj->size) {
        if (val > obj)
    }
}
