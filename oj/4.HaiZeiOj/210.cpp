/*************************************************************************
	> File Name: 212.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 16时21分52秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[30];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int j = 0; j < n; j++) {
        if (j != 0) cout << " ";
        cout << a[j];
    }
    cout << endl;
    return 0;
}
