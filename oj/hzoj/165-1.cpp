/*************************************************************************
	> File Name: 165-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 11时21分28秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int ans = 0;
    for (long long i = 1; i < n; i++) {
        long long k = sqrt(n * n - i * i);
        if (n * n - i * i == k * k) ans += 1;
    }
    cout << ans / 2 << endl;
    return 0;
}
