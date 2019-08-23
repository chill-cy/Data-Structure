/*************************************************************************
	> File Name: oj327.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 20时20分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX_N 2000000


struct Data {
    long long i, j, e;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.e > b.e;
}

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 2) % 2;
    }
} u;
  
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &arr[i].i, &arr[i].j, &arr[i].e);
    } 
    sort(arr, arr + m, cmp);
    u.init(n);
    for (int i = 0; i < m; i++) {
        int fx = u.get(arr[i].i);
        int fy = u.get(arr[i].j);
        if (fx != fy) {
            u.merge(arr[i].i, arr[i].j, 1);
        } else {
            if (u.val[arr[i].i] == u.val[arr[i].j]) {
                printf("%lld\n", arr[i].e);
                return 0;
            } 
        }
    }
    printf("0\n");
    return 0;
}
