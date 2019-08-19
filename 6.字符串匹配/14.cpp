/*************************************************************************
	> File Name: 14.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月19日 星期一 22时12分20秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

char * longestCommonPrefix(char ** strs, int strsSize){
    int min_len = 9999;
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) < min_len) min_len = strlen(strs[i]);
    }
    char *ch_m = (char *)malloc(sizeof(char) * min_len);
    for (int j = 0; j < min_len; j++) {
        for (int i = 1; i < strsSize; i++) {
            if (strs[0][j] == strs[i][j]) {
                ch_m[j] = strs[0][j];
                continue;
            } else {
                ch_m[j] = '\0';
                break;
            }
        }
    }
    return ch_m;
}

int main() {
    int n;
    cin >> n;
    char **str = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        str[i] = (char *)malloc(sizeof(char) * 20);
        cin >> str[i];
    }
    char *s = longestCommonPrefix(str, n);
    cout << s << endl;
    return 0;
}
