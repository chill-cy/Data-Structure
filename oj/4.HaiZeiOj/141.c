/*************************************************************************
	> File Name: 139.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 18时46分57秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a = 'A';
    for (int i = n + 1; i >= 1; i--) {
        for (int k = 1; k <= n - i; k++) {
            cout << " ";
        }
        a -= 1;
        for (int j = i * 2 - 1; j >= 1; j --) {
            if (i == n - 1) {
                printf("%c", a); 
            } else {
                printf("%c", a);
            }
        }
        cout << endl;
    }   
    for (int i = 1; i < n + 1; i++) {
        for (int k = i + 1; k <= n - 1; k++) {
            cout << " ";
        }
        for (int j = 0; j <= 2 * i; j ++) {
            if (i == 0) {
                cout << 'A';
            } else {
                printf("%c", a);
            }
        }
        a += 1;
        cout << endl;
    }
    return 0;
}
