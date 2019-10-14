/*************************************************************************
	> File Name: 110.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 17时06分52秒
 ************************************************************************/

#include <stdio.h>

int main() {
    float X;
    scanf("%f", &X);
    if (X <= 15) printf("%.2f\n", X * 6);
    else if (X > 15){
        printf("%.2f\n", (X - 15) * 9 + 15 * 6);
    }
    return 0;
}
