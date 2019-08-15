/*************************************************************************
	> File Name: 288.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月14日 星期三 22时20分22秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > q1;
priority_queue<int, vector<int>, greater<int> > q2;


int main() {
    int n, m;
    cin >> n >> m;
    int tmp;
    int arr[30005];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1, j = 0; i <= m; i++) {
        cin >> tmp;
        while (j < tmp) {
            ++j;
            if (q1.size() == 0 || q1.top() > arr[j])
                q1.push(arr[j]);
            else 
                q2.push(arr[j]);
        } 
        while (q1.size() > i) {
            int val = q1.top();
            q1.pop();
            q2.push(val);
        }
        while (q1.size() < i) {
            int val = q2.top();
            q2.pop();
            q1.push(val);
        }
        cout << q1.top() << endl;
    }

    return 0;
}

