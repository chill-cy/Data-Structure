/*************************************************************************
	> File Name: oj270-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月02日 星期一 22时47分36秒
 ************************************************************************/

//最大自序和

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespase std;
#define MAX_N 300000
int q[MAX_N + 5], head, tail;
int arr[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> arr[i], arr[i] += arr[i - 1];
    }
    head = tail = 0;
    //q存相关元素的下标，将s[0]的０下标存入
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}
