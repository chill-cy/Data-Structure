/*************************************************************************
	> File Name: oj328.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 19时07分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000
int c[MAX_N + 5];
inline int lowbit(int x) {return x & (-x);}

void add(int x, int val, int n) {
       
}

int main() {
    int n;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        long long val1 = query(a);
        long long val2 = query(a - 1 - val1);
        long long val3 = query(i - 1 - val1);
        long long val4 = query(n - a - val3);
        ans1 += val1 * val2;
        ans2 += val3 * val4;
        add(a, 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
