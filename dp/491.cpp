/*************************************************************************
	> File Name: 491.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 12时27分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int m;

int fac(int n) {
    if (n == 1) return 2;
    int total = 1;
    if (n < m) {
        while (n--) total *= 2;
        return total;
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += fac(n - i);
    }
    return sum;
}

int main() {
    int n;
    cin >> n >> m;
    cout << fac(n) << endl; 
    return 0;
}
