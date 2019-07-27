/*************************************************************************
	> File Name: 130.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 17时26分45秒
 ************************************************************************/

#include <stdio.h>

int main() {
    double m, n;
    scanf("%lf%lf", &m, &n);
    double sum = m;
    sum = sum * (1 + 0.00417);
    for (int i = 0; i < n - 1; i++) {
        sum = (m + sum) * (1 + 0.00417);
    }
    printf("$%.2lf\n", sum);

    return 0;
}
