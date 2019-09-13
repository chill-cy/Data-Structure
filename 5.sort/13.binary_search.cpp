/*************************************************************************
	> File Name: 13.binary_search.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月13日 星期五 15时51分22秒
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

int binary_search1(int *num, int n, int x) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return mid;
}

int binary_search2(int *num, int n) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        printf("l ; %d, r : %d, mid : %d\n", l, r, mid);
        mid = (l + r) >> 1;
        if (num[mid] == 1) l = mid;
        else r = mid - 1;
    }
    return l;
}

int binary_search3(int *num, int n) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (num[mid] == 1) r = mid;
        else l = mid + 1;
    }
    return l == n ? -1 : l;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int arr2[10] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    P(binary_search1(arr1, 10, 11));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 10));
    return 0;
}
