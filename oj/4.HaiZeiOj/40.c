/*************************************************************************
	> File Name: 40.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月19日 星期三 14时35分15秒
 ************************************************************************/

#include <stdio.h>

int step(int n) {
    int total;
    //if (n == 0) total = 0;
    if (n == 1) total = 0;
    if (n == 2 || n == 3 || n == 4) total = 1;
    else total = step(n - 2) + step(n - 3);
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    int sum = step(n);
    printf("%d\n", sum);
    return 0;
}
