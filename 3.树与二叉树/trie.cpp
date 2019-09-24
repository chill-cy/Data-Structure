/*************************************************************************
	> File Name: trie.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月24日 星期二 17时59分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define BASE 26
#define BASE_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

inline int code(char ch) {
    
}

int main() {
    char str[1000];
    int n;
    Node *root = getNewNode();
    
    return 0;
}
