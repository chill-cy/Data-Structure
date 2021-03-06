/*************************************************************************
	> File Name: util.h
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月13日 星期日 14时11分36秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#ifndef _UTIL_H
#define _UTIL_H
#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp;\
}


typedef struct Node {
    int ch;
    int flag;
    int p;
    struct Node *lchild, *rchild;
}Node;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HuffmanTree {
    Node *root;
    int n;
    Code *codes;
} HuffmanTree;

typedef struct Data {
    char ch;
    int num;
} Data;

map<int, int>mp;
int cnt = 0;
Node *arr;

void print_map() {
    map<int, int> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        printf("字符：%d; 频度：%d;\n", it->first, it->second);
    }
}

#endif
