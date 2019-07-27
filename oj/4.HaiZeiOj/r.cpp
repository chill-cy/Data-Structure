/*************************************************************************
	> File Name: r.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 18时57分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    double a;
    cin >> a;
    if (a < 0) {
        printf("%f", -a);
        cout << -a << endl;
    } else {
        cout << a << endl;
    }
    return 0;
}
