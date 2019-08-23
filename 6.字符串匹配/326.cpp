/*************************************************************************
	> File Name: 326.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 15时18分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;

void read(int &n, int &m) {
    cin >> n >> m;
    u.init(n);
    return ;
}

int main() {
    int n, m;
    read(n, m);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans += 1;
            continue;
        }
        int a = u.get(x);
        int b = u.get(y);
        if (a == b) {
            if (d == 1) {
                
            }
        } else if (a != b) {
            if (d == 1 && ) 
        }
        if (d == 1) {
            if (u.get(x) == u.get(y) && u.val[x] != u.val[y]) ans++;
            else if (u.get(x) == u.get(y)){
                u.merge(x, y, 0);
            }
        } else if (d == 2){
            if (x == y) {
                ans += 1;
                continue;
            } else {
                if ((u.val[x] - u.val[y] + 3) % 3 != 2) {
                    ans++;
                } else if ((u.val[x] - u.val[y] + 3) % 3 == 2) {
                    u.merge(x, y, 2);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
