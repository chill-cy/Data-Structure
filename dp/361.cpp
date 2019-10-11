/*************************************************************************
	> File Name: 361.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月12日 星期六 00时20分12秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_N 6000
struct Edge {
    int to, next;
} g[(MAX_N << 1) + 5];
int head[MAX_N + 5], cnt = 0;
int val[MAX_N + 5];
int dp[MAX_N + 5][2];
inline void add(int a, int b) {
    g[++cnt] = {b, head[a]};
    head[a] = cnt;
}

void get_dp(int fa, int x) {
    dp[x][0] = 0;
    dp[x][1] = val[x];
    for (int i = head[x]; i; i = g[i].next) {
        int to = g[i].to;
        if (to == fa) continue;
        get_dp(x, to);
        dp[x][0] += max(dp[to][0], dp[to][1]);
        dp[x][1] += dp[to][0];
    }
    return ;
}

int main(){
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    get_dp(0, 1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
