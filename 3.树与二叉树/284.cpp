/*************************************************************************
	> File Name: 284.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月12日 星期一 19时53分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define MAX_N 10000

struct Data {
    int p,d ;
}arr[MAX_N + 5];

bool cmp (const Data &a, const Data &b) {
    return a.d < b.d;
}
typedef pair<int ,int> PII;
set<PII> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(PII(arr[i].p, arr[i].d));
        } else if (arr[i].p > s.begin()->first){
            s.insert(PII(arr[i].p, s.begin()->second));
            s.erase(s.begin());
        }
    }
    int sum = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        sum += iter->first;
    }
    cout << sum << endl;
    return 0;
}
