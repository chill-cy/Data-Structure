/*************************************************************************
	> File Name: 160.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 10时41分22秒
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <cstdio>
#define PI 3.14
using namespace std;

int main() {
    double r, h;
    cin >> r >> h;
    double S;
    S = (PI * r * r / 2.0 + 2 * r * 2 * r / 2.0) * 2 + (2 * PI * r / 2.0 + 2 * r + sqrt(8.0) * r) * h;
    printf("%.2f", S);
    return 0;
}
