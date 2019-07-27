/*************************************************************************
	> File Name: 193.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 11时18分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
int main() {
    int n, a[MAX_N + 5], k, s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k >> s;
    int x = s - k;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            cout << "Yes" << endl;
            return 0;
        }
        if (a[mid] < x) {
            l = mid + 1;
        }
        if (a[mid] > x) {
            r = mid - 1;
        }
    }
    cout << "No" << endl;
    return 0;
}
