/*************************************************************************
	> File Name: 132.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月06日 星期四 20时55分08秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    long long int a[105];
    scanf ("%d", &n);
    long long int sum = 1;
    for (int i = 0; i < n; i++) {
        scanf ("%lld", &a[i]);  
        sum *= a[i];
    }
    printf ("%lld\n", sum);
    return 0;
}
