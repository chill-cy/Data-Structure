/*************************************************************************
	> File Name: 12.double_array_trie.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月01日 星期二 23时31分31秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node;

typedef struct DATrie {
    int *base, *check;
    int root, size;
} DATrie;

DATrie *getDATrie(int n) {
    DATrie *tree = (DATrie *)calloc(sizeof(DATrie), 1);
    tree->root = 1;
    tree->size = n;
    tree->base = (int *)calloc(sizeof(int), n);
    tree->check = (int *)calloc(sizeof(int), n);
    tree->check[tree->root] = 1;
    return tree;
}

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt += 1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 0, flag;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    }while (!flag);
    return base;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE;)
}
