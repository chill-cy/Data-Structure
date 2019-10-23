/*************************************************************************
	> File Name: yuese_cir-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 22时37分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

int circle(int n, int key) {
    if (n == 1) return 0;
    return (circle(n - 1, key) + key) % n;
}

int main() {
    int n;
    cin >> n;
    int temp = n;
    int sum = 0;
    int m = circle(n, 2) + 1;
    while (m < n) {
        n = m;
        m = circle(n, 2) + 1;
    }
    cout << m + temp << endl;
    return 0;
}
