/*************************************************************************
	> File Name: 139.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 18时46分57秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k <= n - 1; k++) {
            cout << " ";
        }
        for (int j = n - i; j <= n; j++) {
            
            cout << "AA";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int k = 1; k <= n - i; k++) {
            cout << " ";
        }
        for (int j = i; j >= 1; j--) {
            cout << "AA";
        }
        cout << endl;
    }   
    return 0;
}
