/*************************************************************************
	> File Name: 209.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 19时16分33秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
