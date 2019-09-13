/*************************************************************************
	> File Name: oj270.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月08日 星期日 21时07分40秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5], head, tail;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
    head = tail = 0;
    q[tail++] = 0;
    int ans = arr[0];
    for (int i = 1; i <= n; i++) {
        if (arr[i] - arr[q[head]] > ans) ans = arr[i] - arr[q[head]];
        while (taill - head && arr[q[tail - 1]] > arr[i]) tail--;
        q[tail++] = i;
        if (i - q[head] >= m) head++;
    }
    cout << ans << endl;
    return 0;
}
