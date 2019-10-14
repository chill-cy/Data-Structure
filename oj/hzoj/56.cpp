/*************************************************************************
	> File Name: oj56.cpp
	> Author: meng
	> Mail: 2206084014@qq.com
	> Created Time: 2019年06月27日 星期四 18时16分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define MAX_N 10
int fact[MAX_N + 5];
int num[MAX_N + 5];

void init(int n) {
    fact[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        num[i] = 1;
    }
    return ;
}

int get_num(int k, int val, int n, int &g) {
    int step = k / val;
    g = 0;
    for (int t = 0; t <= step; g += (t <= step)) {
        t += num[g];
    }
    k %= val;
    num[g] = 0;
    return k;
}

int main() {
    int x, y;
    scanf("%d %d\n", &x, &y);
    init(x);
    int k = y - 1;
    for (int i = x; i >= 1; i--) {
        int g;
        k = get_num(k, fact[i - 1], x, g);
        printf("%d", g + 1);
    }
    printf("\n");
    return 0;
}

