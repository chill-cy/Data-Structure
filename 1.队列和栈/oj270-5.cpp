/*************************************************************************
	> File Name: oj270-5.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月08日 星期日 21时30分34秒
 ************************************************************************/

#include<iostream>
#include <deque>
#include <algorithm>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
deque<int> q;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    q.push_back(0);
    int ans = arr[0];
    for (int i = 1; i <= n; i++) {
        //if (arr[i] - arr[q.front()] > ans) ans = arr[i] - arr[q.front()];
        ans = max(ans, arr[i] - arr[q.front()]);
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() >= m) q.pop_front();
    }
    cout << ans << endl;
    return 0;
}
