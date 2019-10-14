/*************************************************************************
	> File Name: 137.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 18时23分38秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a = 'A';
    int flag = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == 0 && j == i) {
                cout << "A"; 
                continue;
            }
            a += 1;
            printf("%c", a);
        }
        cout << endl;
    }
    return 0;
}
