/*************************************************************************
	> File Name: oj233-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月04日 星期三 00时38分13秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000
int n, p, h, m;
int res[MAX_N + 5];
struct ind {
    int a, b;
} ind[MAX_N + 5];

bool cmp1(struct ind &a, struct ind &b) {
    if (a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

bool cmp2(struct ind &a, struct ind &b) {
    return a.a == b.a && a.b == b.b;
}

int main() {
    cin >> n >> p >> h >> m;
    res[0] = h;
    for (int i = 0; i < m; i++) {
        cin >> ind[i].a >> ind[i].b;
        if (ind[i].a > ind[i].b) swap(ind[i].a, ind[i].b);
    }
    sort(ind, ind + m, cmp1);
    int end = unique(ind, ind + m, cmp2) - ind;
    for (int i = 0; i < end; i++) {
        res[ind[i].a] -= 1;
        res[ind[i].b - 1] += 1;
    }
    for (int i = 0; i < n; i++) {
        res[i] += res[i - 1];
        cout << res[i] << endl;
    }
    return 0;
}
