/*************************************************************************
	> File Name: 134.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 18时11分06秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int flag = 1;
    for (int i = a; i <= b; i++) {
        if (i % 11 == 0) {
            if (flag == 0) {
                cout << " " << i;
            } else {
                flag = 0;
                cout << i;
                continue;
            }
        }
    }
    cout << endl;
    return 0;
}
