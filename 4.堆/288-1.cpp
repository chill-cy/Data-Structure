/*************************************************************************
	> File Name: 288-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月14日 星期三 23时00分56秒
 ************************************************************************/

#include<iostream>
#include <set>
#define MAX_N 30000
using namespace std;

typedef pair<int, int> PII;
int arr[MAX_N + 5] = {0};

set<PII> s1, s2;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int tmp;
    for (int i = 1, j = 0; i <= m; i++) {
        cin >> tmp;
        while (j < tmp) {
            if (-(s1.begin()->first) > arr[j]) {
                s1.insert(PII(-arr[j], i));
            } else {
                s2.insert(PII(arr[j], i));
            }
            j++;
        }
        while (i > s1.size()) {
            int val;
            val = (-s2.begin()->first);
            s1.insert(PII(val, (s2.begin()->second)));
            s2.erase(s2.begin());
        }
        while (i < s1.size()) {
            int val;
            val = (-s1.begin()->first);
            s2.insert(PII(val, (s1.begin()->second)));
            s1.erase(s1.begin());
        }
        cout << -(s1.begin()->first) << endl;
    }
    return 0;
}
