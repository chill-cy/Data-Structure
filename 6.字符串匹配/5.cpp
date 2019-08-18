/*************************************************************************
	> File Name: 5.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月18日 星期日 16时20分26秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;
#define MAX_N 1000

int expand(char *str, int left, int right, int len) {
    int i, j;
    for (i = left, j = right; i >= 0 && j < len; i--, j++) {
        if (str[i] == str[j]) {
            continue;
        }
        else return j - i - 1;
    }
    return j - i - 1;
}

int main() {
    char str[MAX_N + 5];
    cin >> str;
    int len = strlen(str);
    int max_len = -99999;
    int ind;
    for (int i = 0; i < len; i++) {
        int len1 = expand(str, i, i + 1, len);
        int len2 = expand(str, i, i, len);
        if (len1 < len2) len1 = len2;
        if (len1 > max_len) {
            max_len = len1;
            ind = i;
        }
    }
    for (int i = ind - (max_len - 1) / 2; i <= ind + max_len / 2; i++) {
        cout << str[i];
    }
    cout << endl;
    cout << max_len << endl;
    return 0;
}
