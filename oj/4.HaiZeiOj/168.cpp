/*************************************************************************
	> File Name: 168.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 14时37分06秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i][0] >= 'a' && a[i][0] <= 'z') {
            a[i][0] -= 32;
        }
        for (int j = 1; j < a[i].size(); j++) {
            if (a[i][j] >= 65 && a[i][j] <= 96) {
                a[i][j] += 32;
            }
        }
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
