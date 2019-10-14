/*************************************************************************
	> File Name: 97.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月23日 星期日 19时45分32秒
 ************************************************************************/

#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    long long int sum;
    sum = n * (1 + n) / 2;
    printf("%lld\n", sum);
    return 0;
}
