/*************************************************************************
	> File Name: 185.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 20时04分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int n) {
    if (n == 1 || n == 2) return 1;
    return f(n - 1) + f(n - 2);
}

int main() {
    int n;
    cin >> n;
    int ans = f(n);
    cout << ans << endl;
    return 0;
}
