/*************************************************************************
	> File Name: oj328.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 13时09分24秒
 ************************************************************************/
#include <iostream>
using namespace std;
#define MAX_N 200000
int arr[MAX_N + 5];
int c[MAX_N + 5];
inline int lowbit(int x) { return x & (-x); }
void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}
int query(int x) {
    return (x ? c[x] + query(x - lowbit(x)) : 0);
}

int main() {
    int n;
    long long ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        long long lnum = query(arr[i]);
        ans1 += (arr[i] - lnum - 1) * lnum;
        ans2 += (i - 1 - lnum) * (n - arr[i] - i + 1 + lnum);
        add(arr[i], 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}

