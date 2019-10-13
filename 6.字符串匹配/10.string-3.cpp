/*************************************************************************
	> File Name: 10.string-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月12日 星期六 14时24分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int brute_force(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0, I = len1 - len2 + 1; i < I; i++) {
        int j = 0;
        for (; t[j]; j++) {
            if (t[j] == s[i + j]) continue;
            break;
        }
        if (!t[j]) return i;
    }
    return -1;
}

int sunday(char *s, char *t) {
    int ind[128] = {0};
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0; i < 128; i++) ind[i] = len2 + 1;
    for (int i = 0; t[i])
}
