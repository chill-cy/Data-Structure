/*************************************************************************
	> File Name: kmp-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月17日 星期六 14时29分48秒
 ************************************************************************/

#include<iostream>
#include <string.h>

using namespace std;

#define TEST(func, a, b) {\
    printf("%s (%s) (%s) = %d", #func, a, b, func(a, b));\
}

int Kmp(char *str, char *pattern) {
    int str_len = strlen(str);
    int pa_len = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * pa_len);
    next[0] = -1;
    for (int i = 1; i <= pa_len; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) {
            j = next[j];
        }
        if (pattern[j + 1] == pattern[i]) {
            j++;
            next[i] = j; 
        } else {
            next[i] = -1;
        }
    }
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != pattern[j + 1]) {
            j = next[j];
        }
        if (str[i] == pattern[j + 1]) {
            j++;
        }
        i++;
        if (pattern[j + 1] == '\0') {
            free(next);
            return i - pa_len;
        }
    }

    free(next);
    return -1;
}

int main() {
    char str[1000], pattern[1000];
    cin >> str >> pattern;
    TEST(Kmp, str, pattern);
    return 0;
}
