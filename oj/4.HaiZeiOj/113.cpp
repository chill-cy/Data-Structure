/*************************************************************************
	> File Name: 113.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 20时02分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int is_run(int n) {
    if (n % 100 != 0 && n % 4 == 0 || n % 400 == 0) return 1;
    return 0;
}

int main() {
    int y, m, d;
    cin >> y >> m;
    if (m == 2 && is_run(y)) {
        cout << "29" << endl;
    } else if (m == 2 && !is_run(y)) {
        cout << "28" << endl;
    } else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        cout << "31" << endl;
    } else {
        cout << "30" << endl;
    }
    return 0;
}
