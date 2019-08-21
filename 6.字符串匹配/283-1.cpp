/*************************************************************************
	> File Name: 283.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 23时28分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_M 100000

char arr[MAX_N + 5];
int ans = 1;//成功
struct Node {
    int flag;
    int next[10];
} tree[MAX_N + 5];
int root = 1, cnt = 1;

int getNode () {return ++cnt;}
void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - '0';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    return ;
}

int search(char *str) {
    int p = ind;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < BASE; i++) {
            if (tree[p].next[j] == 0) 
        }
    }
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
        cin >> arr; 
        insert(arr);
        sum += search(arr);
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
