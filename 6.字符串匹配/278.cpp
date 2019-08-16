/*************************************************************************
	> File Name: 278.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月16日 星期五 16时17分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
int ans[MAX_N + 5];

void get_next(char *str, int *nxt) {
    int j = -1;
    nxt[0] = -1;
    for (int i = 1; str[i]; i++) {
        while (j != -1 && str[j + 1] != str[i]) j = nxt[j];
        if (str[j + 1] == str[i]) j += 1;
        nxt[i] = j;
    }
    return ;
}


//初始化循环节长度
int main() {
    int n;
    cin >> n;
    cin >> str;
    get_next(str, nxt);
    for (int i = 0; i < n; i++) {
        if (nxt[i] == -1 || i - nxt[i] != ans[nxt[i]]) {
            ans[i] = i + 1;
        } else {
            ans[i] = ans[nxt[i]];
        }
    }

    return 0;
}
