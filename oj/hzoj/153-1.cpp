/*************************************************************************
	> File Name: 153-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 12时13分54秒
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
    int h = (d + 26 * (m + 1) / 10 + y % 100 + y % 100 / 4 + y / 100 / 4 + 5 * (y / 100)) % 7;
    cout << (h + 5) % 7 + 1 << endl;
    return 0; 
}
