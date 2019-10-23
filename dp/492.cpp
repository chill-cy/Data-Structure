/*************************************************************************
	> File Name: 492.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 23时38分43秒
 ************************************************************************/
/*
 * 对于一个正整数 kk，求出 kk 的所有拆分，并统计输出其中回文数列的个数。所谓回文数列是指该数列中的所有数字，从左向右和从右向左看都相同。
 */
#include<iostream>
using namespace std;

int fac(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 1;
    int sum;
    if (n & 1) sum = fac(n - 1);
    else sum = fac(n - 1) * 2 + 1;
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << fac(n) << endl;
    return 0;
}
