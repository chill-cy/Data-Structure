/*************************************************************************
	> File Name: 150.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 10时40分58秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    int a[205][205];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
