/*************************************************************************
	> File Name: 287.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月12日 星期一 23时54分35秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> que; 

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        que.push(val);
    }
    int sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        int data1 = que.top();
        que.pop();
        int data2 = que.top();
        que.pop();
        sum += data1 + data2;
        que.push(data1 + data2);
    }
    cout << sum << endl;
    return 0;
}
