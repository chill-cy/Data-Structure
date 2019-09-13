/*************************************************************************
	> File Name: oj233-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月03日 星期二 23时33分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10007;

int diff[MAXN];
struct OPT {
    int a, b;
    /*
    inline bool operator < (const OPT &tmp) const {
        return a == tmp.a ? b < tmp.b : a < tmp.a;
    }
    inline bool operator == (const OPT &tmp) const {
        return a == tmp.a && b == tmp.b;
    }*/
} opt[MAXN];

bool cmp1(struct OPT &a, struct OPT &b) {
    if (a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

bool cmp2(struct OPT &a, struct OPT &b) {
    return a.a == b.a && a.b == b.b;
}

int main() {
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        opt[i].a = a, opt[i].b = b;
    }
    sort(opt + 1, opt + 1 + m, cmp1);
    int end = unique(opt + 1, opt + 1 + m, cmp2) - opt - 1;
    for (int i = 1; i <= end; ++i) {
        diff[opt[i].a + 1] -= 1;
        diff[opt[i].b] += 1;
    }
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        cout << diff[i] + h << endl;
    }
    return 0;
}
