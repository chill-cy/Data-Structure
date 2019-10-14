/*************************************************************************
	> File Name: 192.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 11时26分28秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
#define EPSILON 1e-11
int main() {
    double a, a1;
    cin >> a;
    double l = 0, x = a;
   // double mid = (l + r) / 2.0;
    while (fabs(x * exp(x) - a) > EPSILON) {
        x = x - (x * exp(x) - a) / (exp(x) + x);
    }
    printf("%.4f\n", x);
    return 0;
}
