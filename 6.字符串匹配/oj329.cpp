/*************************************************************************
	> File Name: oj329.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月22日 星期四 20时45分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
int c[MAX_N + 5];

inline int lowbit(int x) {return x & (-x);}

void add(int x, int val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

int query(int x) {
    int sum = 0;
    while(x) sum += c[x], x -= lowbit(x);
    return sum;
}

int main() {
    int n, m, pre = 0, now;
    
}
