/*************************************************************************
	> File Name: aaaa.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月20日 星期五 20时57分54秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 200000
long long a[MAX_N + 5], b[MAX_N + 5], c;

int main() {
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (long long j = 0; j < n; j++) {
        scanf("%lld", &b[j]);
    }
    c = a[0] + b[0];
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            c ^= a[i] + b[j];
        }
    }
    c ^= a[0] + b[0];
    printf("%lld\n", c);
    return 0;
}
