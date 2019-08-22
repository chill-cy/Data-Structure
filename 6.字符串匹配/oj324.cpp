/*************************************************************************
	> File Name: oj324.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月22日 星期四 18时50分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5], size[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
            size[i] = 1;
        }
        return ;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(x);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        fa[aa] = bb;
        val[aa] = size[bb];
        size[aa] = size[bb]
}

int main() {
    return 0;
}
