/*************************************************************************
	> File Name: 111.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 17时12分24秒
 ************************************************************************/

#include <stdio.h>

int main() {
    float N;
    scanf("%f", &N);

    if (N <= 3) printf("14\n");
    else if (N > 3) {
        printf("%.1f\n", 14 + 2.3 * (N - 3));
    }
    return 0;
}
