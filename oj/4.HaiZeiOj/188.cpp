/*************************************************************************
	> File Name: 188.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月29日 星期六 16时36分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
int prime[MAX_N + 5] = {0};
/*
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[prime[0]] = i;
        for (int j = i; j <= prime[0]; j++) {
            prime[j * prime[i]] = 1;
        }
    }
    for (int i = m; i <= n; i++) {
        if (prime[prime[0]++] == i) printf("%d\n", i);
    }
    return 0;
}
*/
int main() {
    int m, n;
    cin >> n >> m;
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] >= m && prime[i] <= n) {
            cout << prime[i] << endl;
        }
    }
}
