/*************************************************************************
	> File Name: 10.string-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月14日 星期六 14时15分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int kmp(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    for (int i = 1, j = -1;)
}

int main() {
    
    return 0;
}
