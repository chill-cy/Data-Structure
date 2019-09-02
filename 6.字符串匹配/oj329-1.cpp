/*************************************************************************
	> File Name: oj329-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月24日 星期六 16时07分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
int c[MAX_N + 5];

intline int lowbit(int x) {
    return x & (-x);
}

void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
    int sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    int n, m, pre = 0, now;
    char str[10];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
            case 'C': {
                int a, b, c;
                cin >> a >> b >> c;
                add(a, c, n);
                add(b + 1, -c, n);
            } break;
            case 'Q': {
                int x;
                cin >> x;
                cout << query(x) << endl;
            }
        }
    }
    return 0;
}
