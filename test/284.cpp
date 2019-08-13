/*************************************************************************
	> File Name: 284.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月13日 星期二 00时27分29秒
 ************************************************************************/

#include<iostream>
#include <set>
#include <algorithm>

using namespace std;

#define MAX_N 10000

struct Data {
    int p, d;
}arr[MAX_N + 5];

typedef pair<int, int> PII;

set<PII> s;

bool cmp(const Data &a, const Data &b) {
    return a.d < b.d;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(PII(arr[i].p, i));
        } else if (arr[i].p > s.begin()->first) {
            s.erase(s.begin());
            s.insert(PII(arr[i].p, i));
        }
    }
    int sum = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        sum += iter->first;
    }
    cout << sum << endl;
    return 0;
}
