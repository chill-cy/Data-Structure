/*************************************************************************
	> File Name: 10.trie.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月19日 星期一 19时11分49秒
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
using namespace std;

#define BASE 26
#define BASE_LETTER 'a'
typedef struct Node {
    int flag;//当前结点是否独立成词
    struct Node *next[26];
}Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

inline int code(char ch) {
    return ch - BASE_LETTER;
}

void insert(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[code(str[i])] == NULL) p->next[code(str[i])] = getNewNode();
        p = p->next[code(str[i])];
    }
    p->flag = 1;
    return ;
}

int query(Node *root, char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        p = p->next[code(str[i])];
        if (p == NULL) return 0;
    }
    return p->flag;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return ;
    if (root->flag) printf("%s\n", buff);
    buff[k + 1] = '\0';
    for (int i = 0; i < BASE; i++) {
        buff[k] = BASE_LETTER + i;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
    return ;
}

int main() {
    char str[10000];
    int n;
    Node *root = getNewNode();
    scanf("%d", &n);
    for (int i = 0; i< n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    while (~scanf("%s", str)) {
        printf("query %s, result = %s\n", str, query(root, str) ? "Yes" : "No");
    }
    return 0;
}
