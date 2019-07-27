/*************************************************************************
	> File Name: 116.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 15时47分28秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a[4];
    int max = 0;
    cin >> a[0];
    for (int i = 1; i <= 2; i++) {
        cin >> a[i];
        if (a[i] > a[max]) {
            max = i;
        }
    }
    int b = (max + 1) % 3, c = (max - 1 + 3) % 3;
    if ((a[max] + a[b] > a[c]) && (a[max] + a[c] > a[b]) && (a[b] + a[c] > a[max])) {
        if (pow(a[b], 2) + pow(a[c], 2) > pow(a[max], 2)) {
            cout << "acute triangle";
        } else if (pow(a[b], 2) + pow(a[c], 2) == pow(a[max], 2)){
            cout << "right triangle";
        } else if ((pow(a[b], 2) + pow(a[c], 2) < pow(a[max], 2))){
            cout << "obtuse triangle";
        }
    }else {
            cout << "illegal triangle";
    }
    cout << endl;
    return 0;
}
