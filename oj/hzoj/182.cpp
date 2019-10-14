/*************************************************************************
	> File Name: 182.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 17时56分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++) {
       cin >> a;
       if (a > max) max = a;
    }
    cout << max << endl;
    return 0;
}
