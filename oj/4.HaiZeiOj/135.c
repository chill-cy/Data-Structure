/*************************************************************************
	> File Name: 1351.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月06日 星期四 20时13分42秒
 ************************************************************************/

#include<stdio.h>

int main() { 
    int x, y, m, d;
    scanf ("%d%d%d%d", &x, &y, &m, &d);
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d = d + x;
    for (int i = y; ; i++) {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
            month[2] = 29;
        } else {
            month[2] = 28;
        }
        for (int j = m; j <= 12; j++) {
            if (d - month[j] < 0) {
                printf("%d %d %d\n", y, m, d);
                return 0;
            }
            d = d - month[j];
            m += 1;
            m %= 12;
        }
        y += 1;
    }
    printf("%d %d %d\n", y, m, d);
    return 0;
}
