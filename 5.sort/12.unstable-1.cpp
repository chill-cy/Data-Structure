/*************************************************************************
	> File Name: 12.unstable-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月12日 星期四 21时06分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define swap(a, b) {\
    __typeof(a) _temp = a;\
    a = b, b = _temp;\
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

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[ind], num[i]);
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
    return ;
}

void randint(int *arr, int n) {
    while (n--) arr[n] = rand() % 100;
    return ;
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    int arr[MAX_OP];
    randint(arr, MAX_OP);
    TEST(arr, MAX_OP, select_sort, num, MAX_OP);
    TEST(arr, MAX_OP, quick_sort, num, 0, MAX_OP - 1);
    return 0;
}
