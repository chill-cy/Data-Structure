/*************************************************************************
	> File Name: 12.double_array_trie-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 15时46分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
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
    int base = 0, flag = 1;
    do {
        flag = 1;
        base += 1;
        //扫描一遍当前结点所有的子节点
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            //当前第i个子节点不空且没有被占用
            if (tree->check[base + i] == 0) continue;
            //当前base值不合法，base值加１
            //check值非０当前结点被占用了
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

void buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    for (int i = 0;  i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind; 
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        buildDATrie(base + i, root->next[i], tree);
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ;
}

void clearDA(DATrie *tree) {
    if (tree == NULL) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (abs(tree->check[tree->base[p] + ind]) != p) return 0;
        p = tree->base[p] + ind;
    }
    return tree->check[p] < 0;
}



int main() {
    //cnt字典树中的结点数量
    int n, cnt = 1;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    //字典树中结点数量与要开的空间大小有关
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    } 
    DATrie *tree = getDATrie(cnt * BASE + 5);
    buildDATrie(tree->root, root, tree);
    while(~scanf("%s", str)) {
        printf("search %s, result = %s\n", str, query(tree, str) ? "YES" : "NO");
    }
    clear(root);
    return 0;
}
