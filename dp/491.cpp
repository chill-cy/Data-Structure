/*************************************************************************
	> File Name: 491.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 12时27分49秒
 ************************************************************************/

/*
 * 一个核电站有 nn 个放射物质的坑，排列在一条直线上。如果连续 mm 个坑中放入核物质就会发生爆炸，所以某些坑中就不能放核物质。
 * 对于给定的 nn 和 mm，求不发生爆炸的放置核物质的方案总数
 */

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
