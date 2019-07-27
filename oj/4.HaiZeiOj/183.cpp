/*************************************************************************
	> File Name: 183.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 17时58分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int x) {
    if (x < 0) return 0;
    if (x == 1) return 1;
    if (x > 1 && x % 2 == 0) return 3 * f(x / 2) - 1;
    return 3 * f((x + 1) / 2) - 1;
}

int main() {
    int x;
    cin >> x;
    int ans = f(x);
    cout << ans << endl;
    return 0;
}
