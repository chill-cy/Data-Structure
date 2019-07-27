/*************************************************************************
	> File Name: 213.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 17时02分57秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[35];
    int b[12] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[10 - a[i] / 10] += 1;
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        if (i != 0) cout << " ";
        cout << b[i];
    }
    int sum = 0;
    for (int i = 5; i <= 10; i++) {
        sum += b[i];
    }
    cout << " " << sum << endl;
    return 0;
}
