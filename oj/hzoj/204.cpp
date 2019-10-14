/*************************************************************************
	> File Name: 204.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 18时56分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[35] = {0};
    int c[35] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num[j];
        }
        c[i] = num[i];
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << endl;
    }
    return 0;
}
