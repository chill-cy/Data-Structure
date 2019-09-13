/*************************************************************************
	> File Name: 6.huffman-8.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月09日 星期一 20时14分13秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1000
#define swap(a, b) {\
    __typeof(a) tmp = a;\
    a = b; b = tmp;\
}
typedef struct Data {
    char ch;
    double p;
}Data;

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
    struct Node *root;
    int n;
    Code *codes;
} HaffmanTree;

Data arr[MAX_N + 5];

void insertOnce(Node **arr, int n) {
    for (int i = n; i >= 1; i--) {
        if (arr[i]->p > arr[i - 1]->p) {
            swap(arr[i], arr[i - 1]);
            continue;
        }
        break;
    }
    return ;
}

HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->root = NULL;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->n = n;
    return tree;
}

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

int extractCodes(Node *root, Code *code, int k, int l, char *buff) {
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        code[k].ch = root->ch;
        code[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root, code, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root, code, k + delta, l + 1, buff);
    return delta;
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
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    extractCodes(tree->root, tree->codes, 0, 0, buff);
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
    for (int i = 0; i < tree->n; i++) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
