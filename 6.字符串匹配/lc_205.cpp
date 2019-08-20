/*************************************************************************
	> File Name: lc_205.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月20日 星期二 18时16分44秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int sunday(char *str, char *pattern) {
    #define BASE 128
    int str_len = strlen(str);
    int pa_len = strlen(pattern);
    int ind[BASE] = {0};
    for (int i = 0; i < BASE; i++) {
        ind[i] = pa_len + 1;
    }
    for (int i = 0; i < pa_len; i++) {
        ind[pattern[i]] = pa_len - i;
    }
    for (int i = 0; i < str_len - pa_len + 1;) {
        int flag = 1;
        for (int j = 0; j < pa_len; j++) {
            if (str[i + j] == pattern[j]) continue;
            int fd = ind[str[i + pa_len]];
            i += fd;
            flag = 0;
            break;
        } 
        if (flag) {
            return i;
        }
    }
    #undef BASE
    return -1;
}



bool isIsomorphic(char * s, char * t){
    int len = strlen(s);
    char str[128];
    int num[128] = {0};
    memset(str, 0, sizeof(str));
    for (int i = 0; i < len; i++) {
        if (str[s[i]] == '\0') {
            if (num[t[i]]) return false;
            str[s[i]] = t[i];
            num[t[i]] = 1;
        } else {
            if (str[s[i]] != t[i]) return false;
        }
    }
    return true;
}

int main() {
    char *s = (char *)malloc(sizeof(char) * 10);
    char *t = (char *)malloc(sizeof(char) * 10);
    cin >> s >> t;
    cout << isIsomorphic(s, t);
    return 0;
}
