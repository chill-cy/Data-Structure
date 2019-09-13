/*************************************************************************
	> File Name: oj264.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月03日 星期二 21时20分20秒
 ************************************************************************/

#include<iostream>
#include <stack>
using namespace std;
#define MAX_N 100000
long long arr[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];
int main() {
    int n;
    stack<int> s;
    cin >> n;
    arr[0] = arr[n + 1] = -1;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    s.push(0);
    for (int i = 1; i <= n; i++) {
        while (arr[s.top()] >= arr[i]) s.pop();
        l[i] = i - s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (arr[s.top()] >= arr[i]) s.pop();
        r[i] = s.top() - i;
        s.push(i);
    }
    long long max = 0;
    for (int i = 1; i <= n; i++) {
        l[i] = l[i] + r[i] - 1;
        if (l[i] * arr[i] > max) max = l[i] * arr[i];
    }
    cout << max << endl;
    return 0;
}
