/*************************************************************************
	> File Name: 201.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 16时10分13秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flag = 0;
    sort(a, a + n);
    int ans = 0;
    int b[105];
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) continue;
        if (flag == 0) {
            ans = 1;
            b[ans] = a[i];
            flag = 1;
        } else {
            ans++;
            b[ans] = a[i];
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        if (i != 1) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}
