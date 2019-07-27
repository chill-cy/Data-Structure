/*************************************************************************
	> File Name: 190.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 22时24分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 80000 
#define MAX_M 80000

int prime[MAX_M + 5] = {0};
int is_prime[MAX_N + 5] = {0};
int main() {
    long long n;
    cin >> n;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            is_prime[i] = 0;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int ans = 0;
    for (long long i = 1; prime[i] * 2 <= n; i++) {
        if (!is_prime[prime[i]] && !is_prime[n - prime[i]]) ans++;    
    }
    cout << ans << endl;
    return 0;
}
