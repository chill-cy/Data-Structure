/*************************************************************************
	> File Name: 124.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月06日 星期四 20时45分04秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int xl, pm, age, year;
    scanf ("%d%d%d%d", &xl, &pm, &age, &year);
    if ((pm < 50 || xl >= 1) && (age <= 25 || year >= 5)) {
        printf("ok");
    } else {
        printf("pass");
    }
    printf("\n");
    return 0;
}
