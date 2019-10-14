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
#define EPSILON 1e-6
int main() {
    double a;
    cin >> a;
    double l = 0, r = a;
    while (r - l > EPSILON) {
        double x = (l + r) / 2.0;
        //cout << mid << endl;
        if ((l * exp(l) - a) * (x * exp(x) - a) < 0){
            r = x;
        } else {
            l = x;
        }
    }
    printf("%.4f\n", l);
    return 0;
}
