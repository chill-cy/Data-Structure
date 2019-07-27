/*************************************************************************
	> File Name: 1057.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月07日 星期日 16时42分32秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 30

int n, m;
int ans[MAX_N + 5][MAX_N + 5] = {0};
int keep[MAX_N + 5][MAX_N + 5] = {0};

int f(int set, int m) {
    if (m == 0) return set == 1 ? 1 : 0;
    if (ans[set][m] == 1) return keep[set][m];
    keep[set][m] = f((set - 1 + n) % n , m - 1) + f((set + 1) % n, m - 1);
    ans[set][m] = 1;
    return keep[set][m];
}

int main() {
    scanf("%d%d", &n, &m);
    int ans = f(1, m);
    printf("%d\n", ans);
    return 0;
}mZ
