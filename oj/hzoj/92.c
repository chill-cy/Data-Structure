/*************************************************************************
	> File Name: 92.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月23日 星期日 14时00分49秒
 ************************************************************************/

#include <stdio.h>
#define PI 3.14

int main() {
    float r;
    scanf("%f", &r);
    float circle = 2 * r * PI;
    printf("%.2f\n", 2 * PI * r);
    printf("%.2f\n", r * r * PI);
    return 0;
}
