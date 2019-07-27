/*************************************************************************
	> File Name: 165.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 11时11分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int c; 
    cin >> c;
    int ans = 0;
    for (int i = 1; i < c; i++) {
        for (int j = i; j < c; j++) {
            if (i * i + j * j == c * c) {
                ans += 1;
                //cout << i << " " << j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
