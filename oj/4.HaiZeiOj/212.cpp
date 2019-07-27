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
    string a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    sort(a, a + 10);
    for (int j = 0; j < 10; j++) {
        cout << a[j] << endl;
    }
    return 0;
}
