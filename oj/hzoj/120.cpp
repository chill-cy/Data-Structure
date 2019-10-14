/*************************************************************************
	> File Name: 120.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 20时46分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int is_run(int y) {
    if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0) return 1;
    return 0;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    
    if (m == 2 && is_run(y)) {
        if (d >= 1 && d <= 29)
            cout << "YES"; 
        else cout << "NO";
    } else if (m == 2 && !is_run(y)) {
        if (d >= 1 && d <= 28) {
            cout << "YES";
        } else cout << "NO";
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d >= 1 && d <= 30) {
            cout << "YES";
        } else cout << "NO";
    } else if (m < 1 && m > 12) {
        cout << "NO";
    } else {
        if (d >= 1 && d <= 31) {
            cout << "YES";
        } else cout << "NO";
    }
    if (m < 1 || m > 12) cout << "NO";
    cout << endl;
    return 0;
}
