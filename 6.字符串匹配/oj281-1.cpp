/*************************************************************************
	> File Name: oj281-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 21时34分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 1000000
char str[MAX_N + 5];
struct Node {
    //标记此结点独立成词的个数
    int flag;
    int next[26];
} tree[MAX_N + 5];

int root = 1, cnt = 1;
int getNode () {return ++cnt;}

void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].flag += 1;
    return ;
}

//遍历查找路径上所有独立成词的结点累加和
int Find_ans(const char *t) {
    int p = root, ans = 0, ind;
    for (int i = 0; t[i] && p; i++) {
        ind = t[i] - 'a';
        p = tree[p].next[ind];
        ans += tree[p].flag;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n--) cin >> str, insert(str);
    while (m--) {
        cin >> str;
        int ans = Find_ans(str);
        cout << ans << endl;
    }
    return 0;
}
