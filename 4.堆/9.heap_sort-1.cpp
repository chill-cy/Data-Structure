/*************************************************************************
	> File Name: 9.heap_sort-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月11日 星期三 22时40分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b, b = __temp;\
}
void downUpdata(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; --i) {
        int ind = i;
        downUpdata(arr, n, i);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[i], arr[1]);
        downUpdata(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr %d [", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    output(arr, MAX_OP);
    return 0;
}
