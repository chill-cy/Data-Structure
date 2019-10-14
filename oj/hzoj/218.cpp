/*************************************************************************
	> File Name: 218.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 16时11分50秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

struct student {
    int ind;
    int high;
};

bool cmp(student a, student b) {
    if(a.high == b.high) return a.ind < b.ind;
    return a.high < b.high;
}

int main() {
    int n;
    cin >> n;
    student st[MAX_N + 5];
    for (int i = 0; i < n; i++) {
        cin >> st[i].high;
        st[i].ind = i + 1;
    }
    sort(st, st + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << st[i].ind;
    }
    cout << endl;
    return 0;
}
