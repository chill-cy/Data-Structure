/*************************************************************************
	> File Name: 98.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月23日 星期日 19时49分00秒
 ************************************************************************/

#include <stdio.h>
#define PI 3.14

int main() {
    float r, h;
    scanf("%f%f", &r, &h);
    float S = r * r * PI;
    float V = r * r * PI * h;
    printf("%.2f\n%.2f\n", S, V);
    return 0;
}
