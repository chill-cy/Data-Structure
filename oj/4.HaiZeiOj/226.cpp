/*************************************************************************
	> File Name: 226.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月27日 星期二 22时23分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fast_pow(int a, int b, int p) {
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans % p;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << fast_pow(a, b, p) << endl;
    return 0;
}
