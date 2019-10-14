/*************************************************************************
	> File Name: 127-1.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 10时38分29秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    double sum = x;
    for (int i = 1; i <= n; i++) {
        sum = sum * (1.06);
    }
    cout << (int)sum << endl;
    return 0;
}
