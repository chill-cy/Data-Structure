/*************************************************************************
	> File Name: 324.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 11时29分06秒
 ************************************************************************/

#include<iostream>
#define MAX_N 500000
using namespace std;

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5], size[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
            size[i] = 1;
        }
        return ;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = size[bb];
        size[bb] += size[aa];
        return ;
    }
};

UnionSet u;

int main() {
    int n;
    scanf("%d", &n);
    u.init(n);
    char str[10];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%s%d%d", str, &a, &b);
        switch(str[0]) {
            case 'M' : u.merge(a, b); break;
            case 'C' : {
                if (u.get(a) - u.get(b)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u.val[a] - u.val[b]) - 1);
                }
            } break;
        }
    }
    return 0;
}
