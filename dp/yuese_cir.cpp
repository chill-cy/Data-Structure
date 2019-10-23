/*************************************************************************
	> File Name: yuese_cir.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 22时29分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

int circle(int n, int k) {
    if (n == 1) return 0;
    return (circle(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << circle(n, k) + 1 << endl;
    return 0;
}
