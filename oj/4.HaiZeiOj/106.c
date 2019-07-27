/*************************************************************************
	> File Name: 106.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月24日 星期一 08时54分30秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[10];
    scanf("%s", a);
    int len = strlen(a);
    int sum = 0;
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(a[i], ".")) {
            flag = 1;
        }
        if (flag == 1) {
            sum++;
        }
    }
    sum--;
    //int a = strlen(n);
    printf("%s %d\n", a, sum);
    return 0;
}
/*
int main() {
    float a;
    scanf("%f", &a);
    printf("%f\n", -a);
    return 0;
}*/
