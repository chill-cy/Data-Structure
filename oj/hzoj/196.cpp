/*************************************************************************
	> File Name: 196.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 01时10分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long f(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (n == 4) return 1;
    return f(n - 2) + f(n - 3);
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
