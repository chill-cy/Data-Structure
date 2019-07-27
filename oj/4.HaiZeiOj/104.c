/*************************************************************************
	> File Name: 104.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月24日 星期一 08时12分47秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int flag = 0;
    while (n) {
        if (n % 10 == 9) {
            printf("YES\n"); 
            flag = 1;
            break;
        } 
        n /= 10;
    }
    if (!flag) {
        printf("NO\n");
    }
    return 0;
}
