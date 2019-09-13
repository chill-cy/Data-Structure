/*************************************************************************
	> File Name: oj233-4.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月04日 星期三 11时36分07秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000
int res[MAX_N + 5] = {0};

struct arr {
    int a, b;
} arr[MAX_N + 5];

bool cmp1(const struct arr &a, const struct arr &b) {
    if (a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

bool cmp2(const struct arr &a, const struct arr &b) {
    return a.a == b.a && a.b == b.b;
}

int main() {
    int n, p, h, m;
    int a, b;
    cin >> n >> p >> h >> m;
    res[0] = h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        arr[i].a = a;
        arr[i].b = b;
    }
    sort(arr, arr + m, cmp1);
    int end = unique(arr, arr + m, cmp2) - arr;
    for (int i = 0; i < end; i++) {
        res[arr[i].a] -= 1;
        res[arr[i].b - 1] += 1;
    }
    cout << res[0] << endl;
    for (int i = 1; i < n; i++) {
        res[i] += res[i - 1];
        cout << res[i] << endl;
    }
    return 0; 
}
