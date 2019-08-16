/*************************************************************************
	> File Name: str_algorithm.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月16日 星期五 22时18分42秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;
#define TEST(func, a, b) {\
    printf("%s (%s) : (%s) = %d\n", #func, a, b, func(a, b));\
}
int Kmp(char *str, char *pattern) {
    int max_len = strlen(str);
    int pa_len = strlen(pattern);
    
    int *next = (int *)malloc(sizeof(int) * pa_len);
    next[0] = -1;
    for (int i = 1; i <= pa_len; i++) {
        int j = next[i - 1];
        //失配到第一位
        while (j != -1 && pattern[j + 1] != pattern[i]) {
            //取自身的前缀
            j = next[j];
        }
        //连接前缀最后的位置
        if (pattern[j + 1] == pattern[i]) {
            j += 1;
            next[i] = j;
        } else {
            next[i] = -1;//没有前缀
        }
    } 
    //i指向母串第一位，j模式串走过的位置,
    int i = 0, j = -1;
    while(str[i]) {
        while (j != -1 && str[i] != pattern[j + 1]) {
            j  = next[j];
        }
        if (str[i] == pattern[j + 1]) {
            j += 1;
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
    char str[1000] = {0};
    char pattern[1000] = {0};
    cin >> str >> pattern;
    TEST(Kmp, str, pattern);

    return 0;
}
