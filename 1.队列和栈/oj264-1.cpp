/*************************************************************************
	> File Name: oj264-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月03日 星期二 21时56分17秒
 ************************************************************************/

#include<iostream>
#include <stack>
using namespace std;

#define MAX_N 100000
long long arr[MAX_N + 5], l[MAX_N + 5], r[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    stack<int> s;
    arr[0] = arr[n + 1] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    s.push(0);
    for (int i = 1; i <= n; i++) {
        while (arr[s.top()] >= arr[i]) s.pop();
        l[i] = i - s.top();
        s.push(i);
    }
    if (!s.empty()) s.pop();
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
