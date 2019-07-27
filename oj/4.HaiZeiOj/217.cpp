/*************************************************************************
	> File Name: 217.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 10时43分39秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
int main() {
    int n;
    cin >> n;
    int a[MAX_N + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    int num;
    if (n % 2 == 0) {
        num = n / 2 - 1;
    } else {
        num = n / 2;
    }
    int ans = 0;
    
    for (int j = 0; j <= num; j++) {
        ans++;
        if (a[j] == a[num + 1]) num++;
    }
    cout << a[num] << " " << ans << endl;
    return 0;
}
