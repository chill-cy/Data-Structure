/*************************************************************************
	> File Name: 326-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 17时29分32秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 50000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
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
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }   
};

UnionSet u;

int main() {
    int n, k, x, y, d;
    cin >> n >> k;
    int ans = 0;
    u.init(n);
    for (int i = 0; i < k; i++) {
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans += 1;
            continue;
        }
        if (u.get(x) == u.get(y)) {
            if (d == 1 && u.val[x] != u.val[y]) {
                ans += 1;
                continue;
            }
            if (d == 2) {
                if (x == y || (u.val[x] - u.val[y] + 3) % 3 != 2) {
                    ans += 1;
                    continue;
                }
            }
        } else {
            u.merge(x, y, 2);
        }
    }
    printf("%d\n", ans);
    return 0;
}
