/*************************************************************************
	> File Name: 142.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月06日 星期四 21时12分20秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int is_prime(int i) {
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
            return 0;
        }
    }
    return 1;
}

int is_huiwen(int i) {
    int k = log10(i);
    int t = k;
    for (int j = 1; j <= k / 2 + 1; j++) {
        int w = i / pow(10, t);
        
        if ((w % 10) == i % 10) {
            i /= 10;
            t -= 2;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int flag = 0;
    for (int i = a; i <= b; i++) {
        if (is_prime(i) && is_huiwen(i)) {
            if (flag == 0) {
                printf("%d", i);
                flag = 1;
            } else {
                printf(" %d", i);
            }
        }
    }
    printf("\n");
    return 0;
}
