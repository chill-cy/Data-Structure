/*************************************************************************
	> File Name: 487.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 01时03分48秒
 ************************************************************************/

/*
 * 有一面墙，被垂直的分成了 nn 个区域，现在要涂墙，每块墙壁可以涂成红色、蓝色或白色。但是涂墙时必须满足一下条件：
1.两块相邻的墙不能涂成同一种颜色。
2.蓝色的墙必须涂在白墙和红墙中间。
 现求所有涂墙的方案数。
 */
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
