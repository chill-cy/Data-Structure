/*************************************************************************
	> File Name: 195.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 01时22分18秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
int main() {
    int n, m;
    cin >> n >> m;
    long long int a[MAX_N + 5], b[MAX_N + 5]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1;
        int mid;
        while (l != r) {
            int mid = (l + r + 1) / 2;
            if (a[mid] <= b[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (i) {
            cout << " ";
        }
        cout << a[l];
    }
    cout << endl;
    return 0;
}
