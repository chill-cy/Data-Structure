/*************************************************************************
	> File Name: 253.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月29日 星期六 18时56分19秒
 ************************************************************************/
 
#include <math.h>
#include<iostream>
using namespace std;
#define MAX_N 2500
#include <algorithm>
struct Range {
    double l, r;
}arr[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    if (a.r - b.r) return a.r < b.r;
    return a.r > b.r;
}
int main() {
    int n;
    double d;
    cin >> n >> d;
    int x, y;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[i].l = x - sqrt(d * d - y * y);
        arr[i].r = x + sqrt(d * d - y * y);
        if (y > d) flag = 1;
    }
    if (flag) {
        cout << -1 << endl;
        return 0;
    }
    sort(arr, arr + n, cmp);
    double p = arr[0].r;
    int ans = 1; 
    for (int i = 1; i < n; i++) {
        if (arr[i].l > p) {
            p = arr[i].r;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
