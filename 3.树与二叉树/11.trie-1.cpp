/*************************************************************************
	> File Name: 11.trie-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月25日 星期三 16时26分54秒
 ************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;
#define BASE 26
#define BASE_LETTRE 'a'

typedef struct Node {
    int flag;//是否独立成词
    struct Node *next[BASE];
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

void output(Node *root, int k, char *buff) {
    if (root == NULL) return;
    if (root->flag) printf("%s\n", buff);
    for (int i = 0; i < BASE; i++) {
        buff[k] = BASE_LETTRE + i;
        buff[k + 1] = '\0';
        output(root->next[i], k + 1, buff);
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
}

inline int code(char ch) {
    return ch - BASE_LETTRE;
} 

void insert(Node *root, char *str) {
    Node *p = root;//当前插入单词所在的最后一个结点
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
        if (p == NULL) return 0;//查找单词不存在
    }
    return p->flag;
}

int main() {
    char str[1000];
    int n;
    Node *root = getNewNode();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    while (~scanf("%s", str)) {
        printf("query %s, result = %s\n", str, query(root, str) ? "Yes" : "No");
    }
    return 0;
}
