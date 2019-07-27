/*************************************************************************
	> File Name: 184.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 18时03分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

int keep[35] = {0};

int f(int n) {
    if (n == 1) return 1;
    return 2 * f(n - 1) + 2;
    //if (!keep[n]) keep[n] = 2 * f(n - 1) + 2;
    //else keep[n];
}

int main() {
    int n;
    cin >> n;
    int ans = f(n);
    cout << ans << endl;
    return 0;
}
