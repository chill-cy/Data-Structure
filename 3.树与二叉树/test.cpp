/*************************************************************************
	> File Name: test.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月24日 星期三 13时40分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b, b = temp;\
}

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {
    Node *root;
    int n;
    Code *codes;
} HaffmanTree;

typedef struct Data {

}
