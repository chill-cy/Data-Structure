/*************************************************************************
	> File Name: 161.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 10时51分09秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    double sum = x;
    for (int i = 1; i <= n; i++) {
        sum *= 1.06;
    }
    printf("%.6f", sum);

    return 0;
}
