/*************************************************************************
	> File Name: 10.stable_sort.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月14日 星期三 12时48分01秒
 ************************************************************************/

#include<iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

//插排
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; --j) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        //记录是否发生交换
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return ;
}

void merge_sort(int *num, int l, int r) {
    //数组中不足两个元素，直接返回
    if (r - l <= 1) {
        //区间内只有两个元素
        if (r - l == 1) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    //归并需要一片连续的存储区
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    //指向第一个数组，指向第二个数组，k指向临时存储区
    int p1 = l, p2 = mid + 1, k = 0;
    //第一个数组或者第二个数组有元素
    while (p1 <= mid || p2 <= r) {
        //将一数组元素放入临时存储取：１第二个数组为空，或２第一个数组不空，第一个数组元素小于第二个数组元素
        if (p2 > r || p1 <= mid && num[p1] <= num[p2]) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    //将temp内容拷贝回num数组中
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

//随机生成n个值
void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    int arr[MAX_OP];
    randint(arr, MAX_OP);
    //对相关的排序算法做测试，数组，数组中元素数量，排序算法，数组，数组中元素数量
    TEST(arr, MAX_OP, insert_sort, num, MAX_OP);
    TEST(arr, MAX_OP, bubble_sort, num, MAX_OP);
    TEST(arr, MAX_OP, merge_sort, num, 0, MAX_OP - 1);
    return 0;
}
