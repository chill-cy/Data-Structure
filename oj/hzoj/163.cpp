/*************************************************************************
	> File Name: 163.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 10时57分02秒
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double d = sqrt(a * a + b * b - 2 * a * b * cos(c * acos(-1) / 180));
    printf("%.6f", d);
    return 0;
}
