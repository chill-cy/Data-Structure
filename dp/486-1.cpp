/*************************************************************************
	> File Name: 486.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月22日 星期二 23时43分41秒
 ************************************************************************/
/*
 * 用红色的 1∗11∗1 和黑色的 2∗22∗2 两种规格的瓷砖不重叠地铺满 n∗3n∗3 的路面，求出有多少种不同的铺设方案。
 */
#include<iostream>
using namespace std;

long long fac(long long n) {
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (n == 3) return 5;
    return fac(n - 1) % 12345 + 2 * fac(n - 2) % 12345;
}

int main() {
    long long n;
    cin >> n;
    cout << fac(n) % 12345<< endl;
    return 0;
}
