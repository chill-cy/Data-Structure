/*************************************************************************
	> File Name: 200.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 15时33分49秒
 ************************************************************************/

#include<iostream>
#include <cstdio>

using namespace std;

int main() {
    int N;
    cin >> N;
    double a = 4, b = 7;
    double sum = a / b;
    long long c, d;
    for (int i = 1; i < N; i++) {
        b = a + b;
        a = b - a;
        sum += a / b;
    }
    c = a, d = b;
    printf("%lld/%lld\n", c, d);
    printf("%.2f\n", sum);
    return 0;
}
