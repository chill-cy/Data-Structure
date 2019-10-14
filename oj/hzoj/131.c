/*************************************************************************
	> File Name: 131.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 17时41分21秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int a[105];
    int max = 0, min = 0;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[max]) max = i;
        if (a[i] < a[min]) min = i;
    }
    cout << a[max] - a[min] << endl;
    return 0;
}
