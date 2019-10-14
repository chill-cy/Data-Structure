/*************************************************************************
	> File Name: 126.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 23时31分15秒
 ************************************************************************/

#include <stdio.h>
#define PI 3.14
int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2lf\n", PI * (r1 * r1 - r2 * r2));
    return 0;
}
