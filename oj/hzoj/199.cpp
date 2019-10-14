/*************************************************************************
	> File Name: 199.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 14时29分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int a[12] = {0};
int m;
int keep[MAX_N + 5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int f(int k) {
    int ans = 0;
    if (k < 10) return k;
    if (!keep[k]) {
        for (int i = 0; i < 10; i++) {
            keep[k] += a[i] * f(k - i - 1);
        }
    }
    return keep[k] % m;
}

int main() {
    int k;
    cin >> k >> m;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    int ans = f(k);
    cout << ans << endl;
    return 0;
}
