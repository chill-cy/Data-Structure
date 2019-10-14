/*************************************************************************
	> File Name: 106_1.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 16时51分10秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    double x;
    scanf("%lf", &x);
    if (x >= 0)
        cout << x << endl;
    else 
        cout << x*(-1) <<endl;
    return 0;
}
