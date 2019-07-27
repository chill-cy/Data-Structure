/*************************************************************************
	> File Name: 108.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 16时43分09秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char type;
    float m, n;
    scanf("%c", &type);
    scanf("%f%f", &m, &n);
    if (type == 'r') {
        printf("%.2f\n", m * n);
    } else if (type == 't') {
        printf("%.2f\n", m * n / 2.0);
    }
    return 0;
}
