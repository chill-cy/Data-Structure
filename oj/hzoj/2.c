/*************************************************************************
	> File Name: 2.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月19日 星期三 13时56分19秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int score;
    scanf("%d", &score);
    if (score <= 100 && score >= 85) {
        printf("A");
    } else if (score >= 75) {
        printf("B");
    } else if (score >= 60) {
        printf("C");
    } else if (score >= 0) {
        printf("D");
    }
    return 0;
}
