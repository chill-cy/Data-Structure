/*************************************************************************
	> File Name: 115.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 17时38分20秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y) {
        cout << "100" << endl;
    } else if ((x % 10 == y / 10) && (x / 10 == y % 10)) {
        cout << "20" << endl;
    } else if (x % 10 == y / 10 || x / 10 == y % 10 || x % 10 == y % 10 || x / 10 == y / 10) {
        cout << "2" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
