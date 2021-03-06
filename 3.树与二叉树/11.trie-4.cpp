/*************************************************************************
	> File Name: 11.trie-4.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月26日 星期四 00时13分53秒
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

void output(Node *root, int k, char *buff) {
    if (root == NULL) return ;
    if (root->flag) printf("%s\n", buff);
    for (int i = 0; i < BASE; i++) {
        buff[k + 1] = '\0';
        buff[k] = i + BASE_LETTER;
        output(root->next[i], k + 1, buff);
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    char str[100];
    Node *root = getNewNode();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(root, str);
    }
    output(root, 0, str);
    while (~scanf("%s", str)) {
        printf("query %s, result = %d\n", str, query(root, str));
    }
    clear(root);
    return 0;
}
