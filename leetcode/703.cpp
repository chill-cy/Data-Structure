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

    }
}
