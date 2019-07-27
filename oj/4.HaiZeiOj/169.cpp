/*************************************************************************
	> File Name: 169.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 21时32分24秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define MAX_N 30000
int main() {
    int n;
    cin >> n;
    int a[1005] = {0};
    char b[1005];
    int k;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c >> k;
        if (!a[i]) a[i] = k;
        b[i] = c;
       // cout << a[i] << endl;
    }
    char s[MAX_N + 5];
    cin >> s;
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n; j++) {
            if (b[j] == s[i]) {
                ans += a[j];
            //    cout << a[j] << " ";
            }
        } 
    }
    cout << ans << endl;
    return 0;
}
