/*************************************************************************
	> File Name: 100.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月23日 星期日 21时37分25秒
 ************************************************************************/

#include <stdio.h>

int main() {
    float n;
    scanf("%f", &n);
    float sum = n;
    sum = sum * (1 + 0.00417);
    for (int i = 0; i < 5; i++) {
        sum = (n + sum) * (1 + 0.00417);
    }
    printf("$%.3f\n", sum);

    return 0;
}
