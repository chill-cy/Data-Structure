/*************************************************************************
	> File Name: 129.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 10时36分17秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[1005];
    int min;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i == 1) min = a[1];
        if (min > a[i]) min = a[i];
    }
    printf("%d\n", min);
    return 0;
}
