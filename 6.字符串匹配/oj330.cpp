/*************************************************************************
	> File Name: oj330.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月23日 星期五 20时00分55秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

#define MAX_N 100000
#define lowbit(x) (x & (-x))

struct TreeArray {
    int n, c[MAX_N + 5];
    void init(int n) {
        this->n = n;
        memset(c, 0, sizeof(int) * (n + 1));
    }
    void add(int x, int val) {
        while (x <= n) c[x] += val, x += lowbit(x);
    }
    int query(int x) {
        int sum = 0;
        while (x) sum += c[x], x-= lowbit(x);
        return sum;
    }
};

TreeArray b, B;

int main() {
    long long n, m, pre = 0, now;
    cin >> n >> m;
    b.init(n), B.init(n);
    for (long long i = 1; i <= n; i++) {
        cin >> now;
        b.add(i, now - pre);
        B.add(i, i * (now - pre));
        pre = now;
    }
    char str[MAX_N + 5];
    while (m--) {
        cin >> str;
        switch(str[0]) {
            case 'C': {
                long long l, r, c;
                cin >> l >> r >> c;
                b.add(l, c);
                b.add(r + 1, -c);
                B.add(l, l * c);
                B.add(r + 1, -(r + 1) * c);
            } break;
            case 'Q': {
                long long l, r;
                cin >> l >> r;
                l -= 1;
                long long sr = (r + 1) * b.query(r) - B.query(r);
                long long sl = (l + 1) * b.query(l) - B.query(l);
                cout << sr - sl << endl;
            } break;
        }
    }
    return 0;
}
