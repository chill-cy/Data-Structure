/*************************************************************************
	> File Name: 125.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 22时00分03秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int  h, m, s;
    float t;
    scanf("%d%d%d%f", &h, &m, &s, &t);
    float k = t;
    h += t / 3600;
    t = t - t / 3600 * 3600;
    m += t / 60.0;
    if (m >= 60) {
        h += m / 60;
        m = m - m / 60;
    }
    t = t - t / 60 * 60;
    s += t;
    if (s >= 60) {
        m += s / 60;
        s = s - s / 60;
        if (m >= 60) {
            h += m / 60;
            m = m - m / 60;
        }
    }
    int flag = 1;
    if (h >= 24) {
        h = h - h / 24 * 24;
    }
    if (h > 12) {
        h = h - 12;
        flag = 0;
    }
    if (flag == 0) {
        printf("%d:%d:%dpm\n", h, m, s);
    } else {
        printf("%d:%d:%dam\n", h, m, s);
    }
    printf("%.2f%\n", k / (24 * 3600.0) * 100);
    return 0;
}
