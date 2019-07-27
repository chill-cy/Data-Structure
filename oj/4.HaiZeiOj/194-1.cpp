/*************************************************************************
	> File Name: 194-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 10时30分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

int main() {
    int n, num[MAX_N + 5] = {0}, s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> s;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int ans = s - num[i];
        int l = i + 1, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (ans == num[mid]) {
                cout << "Yes" << endl;
                flag = 1;
                break;
            }
            if (ans < num[mid]) {
                r = mid - 1;
            }
            if (ans > num[mid]) {
                l = mid + 1;
            }
        }
        if (flag == 1) break;
    }
    if (flag == 0) {
        cout << "No" << endl;
    }
    return 0;
}
