/*************************************************************************
	> File Name: 147-1.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 10时51分53秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    if ((str[str.size() - 1]) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
