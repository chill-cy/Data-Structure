/*************************************************************************
	> File Name: kmp-5.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月14日 星期六 22时34分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int kmp(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    for (int i = 1, j = -1; i < len2; i++) {
        while (j != -1 && t[j + 1] != str[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == 0) return i - len2 + 1;
    }
    free(next);
    return -1;
}

int kmp(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    for (int i = 1, j = -1; i < len2; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == 0) return i - len2 + 1;
    }
    free(next);
    return -1;
}

int kmp(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    for (int i = 1, j = -1; i < len2; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == 0) return i - len + 1;
    }
    free(next);
    return -1;
}
