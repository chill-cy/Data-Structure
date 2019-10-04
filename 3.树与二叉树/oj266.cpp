/*************************************************************************
	> File Name: oj266.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 13时08分38秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 1000
#define INF 0x3f3f3f3f
char str[MAX_N + 5];

int calc(char *str, int l, int r) {
    int pos = -1, pri = INF, temp = 0;
    for (int i = l; i <= r; i++) {
        int cur_pri = INF + 1;
        switch (str[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
            case '+':
            case '-': cur_pri = 1 + temp; break;
            case '*':
            case '/': cur_pri = 2 + temp; break;
            case '^': cur_pri = 3 + temp; break;
        }
        if (cur_pri <= pri) {
            pos = i;
            pri = cur_pri;
        }
    }
    if (pos == -1) {
        long long num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    }
    long long a = calc(str, l, pos - 1);
    long long b = calc(str, pos + 1, r);
    switch (str[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (long long)pow(a, b);
    }
    return 0;
}

int main() {
    cin >> str;
    cout << calc(str, 0, strlen(str) - 1) << endl;
    return 0;
}

