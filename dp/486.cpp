/*************************************************************************
	> File Name: 486.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月22日 星期二 23时43分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fac(int n) {
    if (n == 1) return 1;
    if (n == 2) return 3;
    return fac(n - 1) + 2 * fac(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fac(n) << endl;
    return 0;
}
