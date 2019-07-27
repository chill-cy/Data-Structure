/*************************************************************************
	> File Name: 119.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 11时12分39秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int yd = -1, td = 1; 
    int y, m, d;
    cin >> y >> m >> d;
    int y1 = y, m1 = m, d1 = d;
    int c = d;
    int x;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        mth[2] = 29;
    } else {
        mth[2] = 28;
    }
    d += yd;
    if (d <= 0) {
        m -= 1;
        if (m <= 0) {
            m = 12;
            y = y - 1;
        }
        d = mth[m];
        printf("%d %d %d\n", y, m, d);
    } else {
        printf("%d %d %d\n", y, m, d);
    }
    y = y1, m = m1, d = d1;
    d = c + td;
    if (d > mth[m]) {
        d = 1;
        m += 1;
        if (m > 12) {
            m = 1;
            y += 1;
        }
        printf("%d %d %d\n", y, m, d);
    } else {
        printf("%d %d %d\n", y, m, d);
    }
    return 0;
}
