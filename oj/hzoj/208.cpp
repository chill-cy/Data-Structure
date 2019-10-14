/*************************************************************************
	> File Name: 208.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 19时21分55秒
 ************************************************************************/

#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m;
    int a[105] = {0};
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cin >> n;
    int ans = 0;
    sort(a, a + m, greater<int>());    
    int b[35] = {0};
    int k = 0;
    for (int i = 0; i < m - 1; i++) {
        //cout << a[i] << " ";
        if (a[i] == a[i + 1]) {
            b[k]++;
        } else {
            k++;
        }
    }
    //cout << endl;
    for (int i = 0; i < m - 1; i++) {
        if (b[i] + 1 >= n) {
            cout << b[i] + 1 << endl;
            break;
        }
        //cout << b[i] + 1<< endl;
    }
    return 0;
}
