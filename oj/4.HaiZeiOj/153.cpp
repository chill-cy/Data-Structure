/*************************************************************************
	> File Name: 153.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 11时40分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    if (m <= 2) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (d + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    cout << (h + 5) % 7 + 1 << endl;
    return 0; 
}
