/*************************************************************************
	> File Name: 136.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 18时19分34秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i += 7) {
        if (i == 0) continue;
        cout << i << endl;
    }
    return 0;
}
