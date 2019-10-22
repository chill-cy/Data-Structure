/*************************************************************************
	> File Name: 487.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 01时03分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

int add_color(int n) {
    if (n == 1 || n == 2) return 1;
    return (add_color(n - 1) + add_color(n - 2)) * 2;
}
int main() {
    int n;
    cin >> n;
    cout << add_color(n) << endl;
    return 0;
}
