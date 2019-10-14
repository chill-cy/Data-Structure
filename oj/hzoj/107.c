/*************************************************************************
	> File Name: 107.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 16时38分39秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 7 == 0 && n % 2 != 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
