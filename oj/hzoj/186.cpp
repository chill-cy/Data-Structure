/*************************************************************************
	> File Name: 186.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 20时18分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int main() {
    int n;
    cin >> n;
    int a[MAX_N + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int step = 1;
    int ans = 1;
    for (int j = 0; ; j += a[j]) {
        step += a[j];
        if (step > n) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
