/*************************************************************************
	> File Name: 288-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月14日 星期三 23时48分33秒
 ************************************************************************/

#include<iostream>
#include <queue>
#include <algorithm>
#define MAX_N 30000
using namespace std;

int arr[MAX_N + 5] = {0};

priority_queue<int, vector<int>, less<int> > q1;
priority_queue<int, vector<int>, greater<int> > q2;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int t;
    for (int i = 1, j = 0; i <= m; i++) {
        cin >> t;
        while (j < t) {
            j++;
            if (q1.size() == 0 || q1.top() > arr[j]) {
                q1.push(arr[j]);
            } else {
                q2.push(arr[j]);
            }
        }
        while (i < q1.size()) {
            int val = q1.top();
            q2.push(val);
            q1.pop();
        }
        while (i > q1.size()) {
            int val = q2.top();
            q1.push(val);
            q2.pop();
        }
        cout << q1.top() << endl;
    }
    return 0;
}
