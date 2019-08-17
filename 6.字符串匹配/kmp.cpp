/*************************************************************************
	> File Name: kmp.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月16日 星期五 22时55分28秒
 ************************************************************************/

#include<iostream>
#include <string.h>

using namespace std;

#define TEST(func, a, b) {\
    printf("%s (%s) (%s) = %d\n", #func, a, b, func(a, b));\
}


int shift_and(char *str, char *pattern) {
    int code[128] = {0};
    int str_len = strlen(str);
    int pa_len = strlen(pattern);
    for (int i = 0; i < pa_len; i++) {
        //字母出现的在pattern的位置
        code[pattern[i]] |= (1 << i);
    }
    int p = 0;
    for (int i = 0; str[i]; i++) {
        //状态转移,给当前新的开始的可能，
        p = p << 1 | 1;
        //看str[i]当前字符是否匹配成功
        p &= code[str[i]];
        //最后匹配到的状态p到与模式串长度pa_len相等的位置
        if (1 << (pa_len - 1) & p) {
            return i - pa_len + 1;
        }
    }
    return -1;
}

int sunday(char *str, char *pattern) {
    #define BASE 128
    int ind[BASE] = {0};
    int pa_len = strlen(pattern);
    int str_len = strlen(str);
    for (int i = 0; i < BASE; i++) {
        ind[i] = pa_len + 1;
    }
    for (int i = 0; i < pa_len; i++) {
        //这个字符在模式串中的倒数第几位，推动量
        ind[pattern[i]] = pa_len - i;
    }
    for (int i = 0; i < str_len;) {
        int flag = 1;
        for (int j = 0; j < pa_len; j++) {
            if (str[i + j] == pattern[j]) continue;
            //向后移动的量
            int yd = ind[str[i + pa_len]];
            i += yd;
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

int Kmp(char *str, char *pattern) {
    int str_len = strlen(str);
    int pa_len = strlen(pattern);
    int next[pa_len] = {0};
    next[0] = -1;
    for (int i = 1; i <= pa_len; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[i] != pattern[j + 1]) {
            j = next[j];
        }
        if (pattern[i] == pattern[j + 1]) {
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
            return i - pa_len;
        }
    }
    return -1;
}

int main() {
    char str[10000], pattern[1000];
    cin >> str >> pattern;
    TEST(Kmp, str, pattern);
    TEST(shift_and, str, pattern);
    TEST(sunday, str, pattern);
    return 0;
}
