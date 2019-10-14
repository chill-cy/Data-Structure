/*************************************************************************
	> File Name: 147.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 10时44分53秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char str[10005];
    cin >> str;
    int len = strlen(str);
    if ((str[len - 1] - '0') % 2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}
