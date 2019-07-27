/*************************************************************************
	> File Name: 167.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 14时29分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    cout << a.size() << endl;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans++;
        if (a[i] == 'a') {
            cout << ans << endl;
            break;
        }
    }
    a = a.insert(n - 1, b);
    cout << a << endl;
    return 0;
}
