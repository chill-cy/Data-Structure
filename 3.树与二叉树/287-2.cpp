/*************************************************************************
	> File Name: 287-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 11时02分29秒
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

priority_queue<int , vector<int>, cmp> que;

int main() {
    int n, val, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        que.push(val);
    }
    for (int i = 1; i < n; i++) {
        int val1 = que.top();
        que.pop();
        int val2 = que.top();
        que.pop();
        sum += val1 + val2;
        que.push(val1 + val2);
    }
    cout << sum << endl;
    return 0;
}
