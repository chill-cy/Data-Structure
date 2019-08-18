/*************************************************************************
	> File Name: 278-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月18日 星期日 19时42分39秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;
#define MAX_N 1000000

char str[MAX_N + 5] = {0};
int t_next[MAX_N + 5] = {0};
int n, ans[MAX_N + 5] = {0};

void get_next(char *str, int *t_next) {
    int len = strlen(str);
    t_next[0] = -1;
    int j = -1;
    for (int i = 1; i < len; i++) {
        j = t_next[i - 1];
        while (j != -1 && str[i] != str[j + 1]) {
            j = t_next[j];
        }
        if (str[i] == str[j + 1]) {
            j++;
            t_next[i] = j;
        } else {
            t_next[i] = -1;
        }
    }
}

int main() {
    cin >> n;
    cin >> str;
    get_next(str, t_next);
    for (int i = 0; i < n; i++) {
        if (t_next[i] == -1 || i - t_next[i] != ans[t_next[i]]) {
            ans[i] = i + 1;
        } else {
            ans[i] = ans[t_next[i]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == i + 1) continue;
        cout << i + 1 << " " << (i + 1) / ans[i] << endl;
    }
    return 0;
}
