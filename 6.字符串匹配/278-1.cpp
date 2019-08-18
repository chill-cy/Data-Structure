/*************************************************************************
	> File Name: 278-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月18日 星期日 18时58分02秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

#define MAX_N 1000000
char str[MAX_N + 5] = {0};
int nxt[MAX_N + 5] = {0};
int lenth[MAX_N + 5] = {0};



void get_next(char *str, int *next) {
    next[0] = -1;
    //当前位置的前一位的前缀
    int j = -1;
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        j = next[i - 1];
        while (j != -1 && str[i] != str[j + 1]) {
            j = next[j];
        }
        if (str[i] == str[j + 1]) {
            j++;
            next[i] = j;
        } else {
            next[i] = -1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin >> str;
    get_next(str, nxt);
    
    for (int i = 0; i < n; i++) {
        if (nxt[i] == -1 || i - nxt[i] != lenth[nxt[i]]) {
            lenth[i] = i + 1;
        } else {
            lenth[i] = lenth[nxt[i]];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (lenth[i] == i + 1) continue;
        cout << i + 1 << " " << (i + 1) / lenth[i] << endl;
    }
    return 0;
}
