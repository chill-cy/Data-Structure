/*************************************************************************
	> File Name: oj281.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 16时41分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 1000000

struct Node {
    int flag;
    int next[26];
} tree[MAX_N + 5];

int root = 1, cnt = 1;
char str[MAX_N + 5];

int getNode() {
    return ++cnt;
}

void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[])
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n--) cin >> str, insert(str);
    while (m--) cin >> str, cout << query(str) << endl;
    return 0;
}
