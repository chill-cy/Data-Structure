/*************************************************************************
	> File Name: 187.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 20时55分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long f1(int n) {
    if (n == 1) return 1;
    return f1(n - 1) * 2 + 1;
}

long long f2(int n) {
    if (n == 1) return 1;
    return f2(n - 1) * 2 + n;
}
int main() {
    int n;
    cin >> n;
    cout << f1(n) << " " << f2(n) << endl;
    return 0;
}
