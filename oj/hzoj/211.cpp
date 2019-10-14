/*************************************************************************
	> File Name: 211.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 16时54分05秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[35];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
