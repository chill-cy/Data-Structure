/*************************************************************************
	> File Name: 99.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月23日 星期日 21时23分04秒
 ************************************************************************/

#include <stdio.h>

int main() {
    float v, a;
    scanf("%f%f", &v, &a);
    float l = (v * v) / (2 * a);
    printf("%.2f\n", l);
    return 0;
}
