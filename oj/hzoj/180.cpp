/*************************************************************************
	> File Name: 180.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 17时28分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long pow(int n) {
    long long p = 1; 
    for (int i = 0; i < n; i++) {
        p *= 2;
    }
    return p;
}

int main() {
    int n;
    cin >> n;
    long long sum = pow(n);
    cout << sum << endl;
    return 0;
}
