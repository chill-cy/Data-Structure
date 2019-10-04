/*************************************************************************
	> File Name: oj270.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 10时20分02秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 300000
long long int arr[MAX_N + 5] = {0}, q[MAX_N + 5] = {0};

long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}

int main() {
    long long int n, m, ans = 0;
    scanf("%lld%lld", &n, &m);
    for (long long int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    long long int head = 0, tail = 1;
    for (long long int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while ((tail - head) && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail] = i;
        tail++;
        if (q[head] == i - m) head++;
    }
    printf("%lld\n", ans);
}
