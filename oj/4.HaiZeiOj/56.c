/*************************************************************************
	> File Name: 56.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 18时17分10秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10
int num[MAX_N + 5];
int fact[MAX_N + 5];

void init(int n) {
    fact[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        num[i] = 1;
    }
    return ;
} 

int get_num(int k, int val, int n, int &x) {
    int step = k / val;
    x = 0;
    for (int t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    k %= val;
    num[x] = 0;
    return k;
}
int main() {
    int k;
    int n;
    cin >> n >> k;
    k = k - 1;
    for (int i = n; i >= 1; i--) {
        int x;
        k = get_num(k, fact[i - 1], n, x);
        cout << x;
    }
    cout << endl;
    return 0;
}
