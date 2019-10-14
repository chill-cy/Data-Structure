/*************************************************************************
	> File Name: 157-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 09时44分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = i; j < n; j++) {
            cout << (char)('A' + j);
        }
        for (int j = n - 2; j >= i; j--) {
            cout << (char)('A' + j);
        }
        cout << endl;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = i; j < n; j++) {
            cout << (char)('A' + j);
        }
        for (int j = n - 2; j >= i; j--) {
            cout << (char)('A' + j);
        }
        cout << endl;
    }
    
    return 0;
}
