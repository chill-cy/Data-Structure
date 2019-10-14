/*************************************************************************
	> File Name: 226-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月29日 星期四 20时51分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long fast_pow(long a, long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans % p;
}


int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << fast_pow(a, b, p) << endl;
    return 0;
}
