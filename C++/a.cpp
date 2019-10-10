/*************************************************************************
	> File Name: a.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月10日 星期四 23时00分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a = 5, b = 6;
    const int &n = a;
    n = 4;
    //int *const k = b;
    //n = &b;
    // a++;
    //cout << *k << endl;
    cout << n << endl;
    return 0;
[<64;47;28M]
