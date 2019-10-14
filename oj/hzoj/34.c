/*************************************************************************
	> File Name: 34.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月19日 星期三 14时31分25秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        printf("L\n");
    } else {
        printf("N\n");
    }
    return 0;
}
