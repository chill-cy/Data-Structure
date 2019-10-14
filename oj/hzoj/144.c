/*************************************************************************
	> File Name: 144.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 00时21分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char a[105];
    memset(a, 0, sizeof(a));
    cin >> a;
    int len = strlen(a);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 'A') sum += 1;
    }
    cout << sum << endl;
    return 0;
}
