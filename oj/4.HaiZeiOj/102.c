/*************************************************************************
	> File Name: 102.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 09时47分17秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int a, b, c, t1;
    cin >> a >> b >> c >> t1;
    double w = (1.0 / a + 1.0 / b) * t1;
    double t2 = (1 - w) / (1.0 / a + 1.0 / b - 1.0 / c);
    printf("%.2lf\n", t1 + t2);
    return 0;
}
