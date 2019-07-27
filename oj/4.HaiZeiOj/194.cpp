/*************************************************************************
	> File Name: 194.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 10时01分46秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int main() {
    int n;
    cin >> n;
    int a[MAX_N + 5] = {'0'};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s;
    cin >> s;
    int l = 0, r = n - 1;
    int flag = 0;
    while (l <= r) {
        if (a[l] + a[r] == s) {
            flag = 1;
            cout << "Yes" << endl;
            break;
        } 
        if (a[l] + a[r] < s) {
            l++;
        }
        if (a[l] + a[r] > s) {
            r--;
        }
    }
    if (flag == 0) {
        cout << "No" << endl;
    }
    return 0;
}
