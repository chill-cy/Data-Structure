/*************************************************************************
	> File Name: 133.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 17时52分28秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << i << "*" << j << "=" << i * j;
            if (j != n) {
                cout << "\t";
            }
        }
        cout << endl;
    }
    return 0;
}
