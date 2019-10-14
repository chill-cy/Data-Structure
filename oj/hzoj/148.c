/*************************************************************************
	> File Name: 148.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 10时13分15秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char a[55];
    scanf("%s", &a);
    int len = strlen(a);
    //printf("%c%c", a[0], a[len - 1]);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}
