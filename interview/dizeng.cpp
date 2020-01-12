/*************************************************************************
	> File Name: dizeng.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 19时41分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[100];
int num[100];
int main() {
    int n, k;
    cin >> n >> k;//k步长
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    int len = 1, max = 0, sub = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] + k == ans[i + 1]) {
            len++;
        } else {
            if (len > max) {
                max = len;
                sub = i;
            }
            len = 1;
        }
        if (i == n - 2 && ans[i] + k == ans[i + 1]) {
            max = len > max ? len : max;
            sub = i + 1;
        }
    }
    for (int i = sub - max + 1; i <= sub; i++) {
        if (i != sub - max + 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
