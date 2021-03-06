/*************************************************************************
	> File Name: 489.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 01时30分14秒
 ************************************************************************/

/*
 * 输入一个整数 n，求所有的 n 位数中，有多少个数中含有偶数个数字 3。
 */
#include<iostream>
using namespace std;
#define MAX_N 1000

long long ans[MAX_N + 5][2];
int fac(int n, int key) {
    if (n == 1) return 0;
    if (n == 2 && key == 0) return 1;
    else if (key == 0) return fac(n - 1, 0) * 9 + fac(n - 1, 1);
    else if (key == 1) return fac(n - 1, 0) + fac(n - 1, 1) * 9;
}

int main() {
    int n;
    cin >> n;
    ans[1][0] = 8;
    ans[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i][0] = (ans[i - 1][0] * 9 + ans[i - 1][1]) % 12345;
        ans[i][1] = (ans[i - 1][0] + ans[i - 1][1] * 9) % 12345;
    }
    cout << ans[n][0] << endl;
    return 0;
}
