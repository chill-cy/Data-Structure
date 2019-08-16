/*************************************************************************
	> File Name: string_algorithm-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月16日 星期五 14时57分57秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define TEST(func, a, b) {\
    printf("%s(\"%s\", \"%s\") = %d\n", #func, a, b, func(a, b));\
}

int BruteForce(char *str, char *pattern) {
    for (int i = 0; str[i]; i++) {
        int flag = 1;
        for (int j = 0; pattern[j]; j++) {
            if (str[i + j] == pattern) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = 1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while(j != -1 && pattern[j + 1] != pattern[i]) j = next[i];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (str[i]) {
        
        while (j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        } 
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    } 
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while(j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        } 
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for (int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (str[i] == pattern[j + 1]) {
            j += 1;
        } 
        i += 1;
        if (pattern[j + 1] == 0) return i - strlen(pattern);
    }
    return -1;
}

int KMP(char *str, char *pattern) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for(int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while()
}
