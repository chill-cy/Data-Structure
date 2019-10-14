/*************************************************************************
	> File Name: 157.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月01日 星期一 00时44分32秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        cout << i;
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << " ";
        }
        if (i == 0) {
            cout << endl;
            break;
        }
        cout << i<< endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        cout << i;
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << " ";
        }
        cout << i << endl;
    }
    return 0;
}
