/*************************************************************************
	> File Name: prime.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月19日 星期一 19时07分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int prime[MAX_N + 5] = {0};

void get_prime(int n) {
    for (int i = 1; i < n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = prime[])
    }
}

int main() {
    int n;
    cin >> n;
    get_prime(n);
    for (int i = 1; i < prime[0]; i++) {
        cout << prime[i] << " ";
    }
    cout << endl;
    return 0;
}
