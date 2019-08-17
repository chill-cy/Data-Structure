/*************************************************************************
	> File Name: 10.trie.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月17日 星期六 16时33分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(1, sizeof(Node));
    return p;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

void insert(Node *node, const char *s) {
    Node *p = node;
    for (int i = 0; s[i]; i++) {
        if (p->next[s[i] - BASE_LETTER] == NULL) {
            
        }
    }
}

int main() {

    return 0;
}
