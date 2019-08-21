/*************************************************************************
	> File Name: oj71.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 20时02分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        return get(fa[x]);
    }
    int merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;


void read(int &n, int &m) {
    cin >> n >> m;
}

int main() {
    int n, m;
    read(n, m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1){
            u.merge(b, c);
        } else {
            cout << (u.get(b) == u.get(c) ? "Yes" : "No");
        }
    }    
    return 0;
}
