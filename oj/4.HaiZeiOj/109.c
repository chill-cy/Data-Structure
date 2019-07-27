/*************************************************************************
	> File Name: 109.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 16时59分43秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int flag = 0;
    while (n) {
        if ((n % 10) % 2 == 0) {
            printf("YES\n");
            flag = 1;
            break;
        } 
        n /= 10;
    }
    if (flag == 0) printf("NO\n");
    return 0;
}
