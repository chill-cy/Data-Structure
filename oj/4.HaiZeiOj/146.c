/*************************************************************************
	> File Name: 146.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 09时42分34秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char a[55];
    scanf("%s", &a);
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] == 'z') {
            a[i] = 'a';
        } else if (a[i] == 'Z') {
            a[i] = 'A';
        } else if ((a[i] < 'z' && a[i] >= 'a') || (a[i] >= 'A' && a[i] < 'Z')){
            a[i] += 1;
        }
        //printf("%c", a[i]);
    }
    for (int i = 0; i < len; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
   // printf("%s\n", a);
    return 0;
}
