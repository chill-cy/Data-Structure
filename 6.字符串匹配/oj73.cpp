/*************************************************************************
	> File Name: oj73.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月22日 星期四 14时19分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000
#define MAX_M 1000000
struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x - fa[x] ? get))
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    u.
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (i)
        }
    }

    return 0;
}
