/*************************************************************************
	> File Name: 489.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 01时30分14秒
 ************************************************************************/

/*
 * 输入一个整数 n，求所有的 n 位数中，有多少个数中含有偶数个数字 3。
 */
#include<iostream>
using namespace std;

int fac(int n, int key) {
    if (n == 1) return 0;
    if (n == 2 && key == 0) return 1;
    else if (key == 0) return fac(n - 1, 0) * 9 + fac(n - 1, 1);
    else if (key == 1) return fac(n - 1, 0) + fac(n - 1, 1) * 9;
}

int main() {
    int n;
    cin >> n;
    cout << (fac(n, 0) + fac(n, 1)) % 12345 << endl;
    return 0;
}
