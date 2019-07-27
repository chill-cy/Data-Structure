/*************************************************************************
	> File Name: 204.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 18时56分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int num[35] = {0};
    double c[35] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[j];
            c[i] += num[j];
        }
        c[i] /= m;
    }
    for (int i = 0; i < n; i++) {
        printf("%.6f\n", c[i]);
    }
    return 0;
}
