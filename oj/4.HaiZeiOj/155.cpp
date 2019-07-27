/*************************************************************************
	> File Name: 155.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 14时04分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans[35] = {0};
    ans[1] = 3;
    int sum = 3;
     
    for (int i = 1; i < n; i++) {
        ans[i + 1] = ans[i] +  2 * i;
        sum += ans[i + 1];
    }
    for (int j = 1; j <= n; j++) {
        cout << ans[j] << endl;
    }
    cout << sum << endl;
    return 0;
}
