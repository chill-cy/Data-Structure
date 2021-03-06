/*************************************************************************
	> File Name: oj322-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 12时27分56秒
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;

#define MAX_N 1000000
map<int, int> ind;
struct Node {
    int i, j, e;
} arr[MAX_N + 5];

struct Unionset {
    int fa[(MAX_N << 1) + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : fa[get(x)]);
    }
    void merge(int a, int b) {
        fa[get(a)] = fa[b];
    }
} u;

void solve() {
    int n, cnt = 0;
    ind.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].i >> arr[i].j >> arr[i].e;
        if (ind.find(arr[i].i) == ind.end()) ind[arr[i].i] = (++cnt);
        if (ind.find(arr[i].j) == ind.end()) ind[arr[i].j] = (++cnt);
        arr[i].i = ind[arr[i].i];
        arr[i].j = ind[arr[i].j];
    }
    u.init(cnt);
    for (int i = 0; i < n; i++) {
        if (arr[i].e != 1) continue;
        u.merge(arr[i].i, arr[i].j);
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i].e == 1) continue;
        if (u.get(arr[i].i) != u.get(arr[i].j)) continue;
        flag = 0;
        break;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return ;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
