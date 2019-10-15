/*************************************************************************
	> File Name: 322.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 10时20分39秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

#define MAX_N 1000000
map<int, int> ind;

struct Data {
    int i, j, e;
} arr[MAX_N + 5];

struct UnionSet {
    int fa[(MAX_N << 1) + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &arr[i].i, &arr[i].j, &arr[i].e);
            if (ind.find(arr[i].i) == ind.end()) ind[arr[i].i] = (++cnt);
            if (ind.find(arr[i].i) == ind.end()) ind[arr[i].j] = (++cnt);
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
        printf("%s", flag ? "YES" : "NO");
        cnt = 0;
        ind.clear();
    }
    return 0;
}
