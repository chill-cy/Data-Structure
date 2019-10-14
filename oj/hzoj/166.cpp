/*************************************************************************
	> File Name: 166.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 11时31分32秒
 ************************************************************************/

#include<iostream>
#include <cstring>

using namespace std;

int main() { 
    string a, b;
    int n;
    cin >> a >> n >> b;
    if (a.size() > 100) {
        cout << 100 << endl;
    } else {
        cout << a.size() << endl;
    }
    a = a.insert(n - 1, b);
    cout << a << endl;
    int ans = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        ans++;
        if (a[i] == 'x') {
            cout << ans << endl;
            break;
        }
    }
   // cout << ans << endl;
    return 0;
}
