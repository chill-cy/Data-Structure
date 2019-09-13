/*************************************************************************
	> File Name: 6.huffman-9.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月10日 星期二 10时05分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b) {\
    __typeof(a) tmp = a;\
    a = b; b = tmp;\
}
#define MAX_N 1000

typedef struct Node {
    char ch;
    int p;
    struct Node *next[2];
} Node;

typedef struct Data {
    char ch;
    double p;
} Data;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {
    struct Node *root;
    int n;
    Code *codes;
} HaffmanTree;

Data arr[MAX_N + 5];

HaffmanTree *getNewTree (int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->root = NULL;
    tree->n = n;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    return tree;
}

Node *getNewNode(Data *obj) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->ch = (obj ? obj->ch : 0);
    node->p = (obj ? obj->p : 0);
    node->next[0] = node->next[1] = NULL;
    return node;
}

int extract(Node *root, Code *codes, int k, int l, char *buff) {
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        codes[k].ch = root->ch;
        codes[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extract(root->next[0], codes, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extract(root->next[1], codes, k + delta, l + 1, buff);
    return delta;
}

void insertOnce(Node **nodes, int n) {
    for (int i = n; i >= 1; i--) {
        if (nodes[i]->p > nodes[i - 1]->p) {
            swap(nodes[i], nodes[i - 1]);
            continue;
        }
        break;
    }
    return ;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = n - 1; i >= 1; i--) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i];
        p->next[1] = nodes[i - 1];
        p->p = p->next[0]->p + p->next[1]->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * 10);
    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    tree->n = n;
    extract(tree->root, tree->codes, 0, 0, buff);
    free(nodes);
    free(buff);
    return tree;
}

int main() {
    int n; 
    scanf("%d", &n);
    char str[10];
    for (int i = 0; i < n; i++) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
