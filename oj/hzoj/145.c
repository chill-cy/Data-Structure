/*************************************************************************
	> File Name: 145.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 09时21分17秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a[25][105];
    int len;
    int max = 0;
    cin >> a[0];
    int len_0 = strlen(a[0]);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        len = strlen(a[i]);
        if (strlen(a[max]) < len) max = i; 
    }
    printf("%s\n", a[max]);
    return 0;
}
