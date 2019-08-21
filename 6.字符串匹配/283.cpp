/*************************************************************************
	> File Name: 283.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 23时28分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

char arr[MAX_N + 5][15];
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
    int p = root, cnt = 0;
    int flag = 0;
    for (int i = 0; str[i] && p; i++) {
        p = tree[p].next[str[i] - '0'];
        for (int i = 0; i < 10; i++) {
            if (tree[p].next[i] != 0) break;
        }
        if (i == 10 && cnt == 1) {
            flag = 1;
        }
        cnt += tree[p].flag;
        if (cnt > 1) flag = 0;
    }
    if (flag = 1 && cnt == 1) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    while (n) {
        cin >> arr[n]; 
        insert(arr[n]);
        n--;
    }
    for (int i = 0; i < n; i++) {
        sum += search(arr[i]);
    }

    if (!sum) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
