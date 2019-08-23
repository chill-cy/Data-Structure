/*************************************************************************
	> File Name: oj323-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 11时12分27秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000
struct Data {
    int p, d;
} arr[MAX_N + 5];

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

bool cmp(const Data &a, const Data &b) {
    return a.p > b.p;
}

UnionSet u;

int main() {
    int n;
    while (scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &arr[i].p, &arr[i].d);
        }
        sort(arr, arr + n, cmp);
        u.init(MAX_N);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (u.get(arr[i].d) == 0) continue;
            ans += arr[i].p;
            int day = u.get(arr[i].d);
            u.merge(day, day - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
