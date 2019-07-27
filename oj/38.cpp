/*************************************************************************
	> File Name: 38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月07日 星期日 20时28分50秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 10000000
#define MAX_M 100
int *num;
char *keep[MAX_M + 5] = {0};

int f(int n) {
    if (n == 1) return 1;
    if (n == 0) return 1;
    if (keep[n][0]) return *keep[n];
    keep[n] = (char *)(f(n - 1) + f(n - 2));
    int len = 0;
    int kp = keep[n];
    while (kp) {
        kp /= 10;
        len++;
    }
    if (keep[0] < len) keep[0] = len;
    for (int j = 0; j < len; j++) {
        keep[n][len - j] += (keep[n][j] - '0');
    }
    for (int j = 1; j <= keep[0]; j++) {
        if (keep[j] < 10) continue;
        keep[n][j + 1] += keep[n][j] / 10;
        keep[n][j] %= 10;
        keep[n][0] += (j == keep[n][0]);
    }
    return *keep[n];
}

int main() {
    int n;
    scanf("%d", &n);
    int ans = f(n);
    printf("%d\n", ans);
    return 0;
}
