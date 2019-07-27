/*************************************************************************
	> File Name: 101.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月23日 星期日 22时51分39秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    int sum = 0;
    scanf("%d", &n);
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);
    return 0;
}
