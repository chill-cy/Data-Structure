/*************************************************************************
	> File Name: 179.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 17时06分15秒
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define EPSILON 0.0000001
int main() {
    double a = -20, b = 20, p, q;
    cin >> p >> q;
    double mid = (a + b) / 2.0;
    while(abs(p * mid + q) > EPSILON) {
        mid = (a + b) / 2.0;
        if ((p * mid + q) * (p * a + q) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    } 
    printf("%.4f", mid);
    return 0;
}
