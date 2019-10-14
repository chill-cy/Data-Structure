/*************************************************************************
	> File Name: 164.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 11时06分27秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == a / b * b) cout << a / b << endl;
    else cout << a / b + 1 << endl;
    return 0;
}
