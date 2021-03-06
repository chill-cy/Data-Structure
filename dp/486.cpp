/*************************************************************************
	> File Name: 486.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月22日 星期二 23时43分41秒
 ************************************************************************/
/*
 * 用红色的 1∗11∗1 和黑色的 2∗22∗2 两种规格的瓷砖不重叠地铺满 n∗3n∗3 的路面，求出有多少种不同的铺设方案。
 */
#include<iostream>
using namespace std;

#define MAX_N 1000
long long ans[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    ans[1] = 1;
    ans[2] = 3;
    for (int i = 3; i <= n; i++) {
        ans[i] = ans[i - 1] + 2 * ans[i - 2];
        ans[i] %= 12345;
    }
    cout << ans[n] << endl;
    return 0;
}
