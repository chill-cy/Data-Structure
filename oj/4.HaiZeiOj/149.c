/*************************************************************************
	> File Name: 149.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 10时23分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char s[55];
    scanf("%[^\n]s", &s);
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            sum = 0;
            continue;
        }
        sum++;
    }
    printf("%d\n", sum);
    return 0;
}
