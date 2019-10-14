/*************************************************************************
	> File Name: 219.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 11时21分26秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20000
int main() {
    int n, l1, r1, l2, r2;
    int a[MAX_N + 5];
    cin >> n;
    cin >> l1 >> r1 >> l2 >> r2;
    l1 -= 1, l2 -= 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a + l1, a + r1);
    sort (a + l2, a + r2, greater<int>());
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
