/*************************************************************************
	> File Name: oj270.c
	> Author: meng
	> Mail: 2206084014@qq.com
	> Created Time: 2019年07月17日 星期三 15时38分01秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 300000
long long q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];

long long max(long long m, long long n) {
    if (m > n) return m;
    return n;
}

int main() {
    long long n, m, ans;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    printf("%lld\n", ans);
    return 0;
}
