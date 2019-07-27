/*************************************************************************
	> File Name: 1290.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年04月22日 星期一 22时22分42秒
 ************************************************************************/

#include <stdio.h>

void swap (int *m, int *n) {
    int *temp = m;
    m = n;
    n = temp;
    return ;
} 

int main() {
    int m, n;
    char S[10] = "Stan wins";
    char O[15] = "Ollie wins";
    while (scanf("%d%d", &m, &n)) {
        if (m < n) swap(&m, &n);
        if (m % n == 0) printf("%s\n", S);
        else {
            if (m % n == 0 && m / n >= 2) printf("")
        }
    return 0;
}
