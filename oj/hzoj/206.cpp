/*************************************************************************
	> File Name: 206.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 21时46分29秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double b[35] = {0};
    double a[35][35] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[j] += a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        //printf("%.1f\n", b[i]);
        cout << b[i] << endl;
    }
    return 0;
}
