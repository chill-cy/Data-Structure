/*************************************************************************
	> File Name: 128.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 09时34分01秒
 ************************************************************************/

#include <stdio.h>
  
int main() {
    float n;
    scanf("%f", &n);
    float arv = 0;
    float sum = 0;
    float a[1005];
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
        sum += a[i];
    }
    arv = sum / n;
    
    printf("%.2f\n", arv);
    return 0;
}
