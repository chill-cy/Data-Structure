/*************************************************************************
	> File Name: 282.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 22时23分16秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
#define MAX_N 3200000
#define MAX_M 100000
#define BASE 30
int arr[MAX_M + 5];

struct Node {
    int num;
    int next[2];
} tree[MAX_N + 5];

int root = 1, cnt = 1;//记录当前所用的最大下标

int getNode () {return ++cnt;};

void insert (int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 << i) & num);
        if (!tree[p].next[ind]) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].num = num;
    return ;
}

int search(int num) {
    int p = root;
    for (int i = BASE; i >= 0; i--) {
        int ind = !!((1 >> i) & num);
        int re_ind = !ind;
        if (tree[p].next[re_ind]) p = tree[p].next[re_ind];
        else p = tree[p].next[ind];
    } 
    return num ^ tree[p].num;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        insert(arr[i]);
    }
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        max_num = max(max_num, search(max_num));
    }
    cout << max_num << endl;
    return 0;
}
