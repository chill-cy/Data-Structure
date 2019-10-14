/*************************************************************************
	> File Name: 127.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 23时38分38秒
 ************************************************************************/

#include <stdio.h>

double get(double x, double n) {
    if (n == 0) return x;
    x *= (1 + 0.06);
    return get(x, n - 1);
}

int main() {
    double x, n;
    scanf("%lf%lf", &x, &n);
    int sum = 0;
    sum = (int)get(x, n);
    printf("%d\n", sum);
    return 0;
}
