/*************************************************************************
	> File Name: 10.trie-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 14时14分47秒
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
    Node *p = root;
    int cnt = 0;
    for (int i = 0; i < str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt++;
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

int getBasevalue(Node *root, DATrie *tree) {
    int base = 1, flag;
    do {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}
//当前编号结点所对应的
int build_DATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBasevalue(root, tree);//确定Base值
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = build_DATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER; 
        if ((tree->check[tree->base[p] + ind]) != 0) return 0;
        p = tree->base[p] + ind;
    }
    return tree->check[p] < 0;
}

void clearDA(DATrie *tree) {
    if (tree == NULL) return ;
    free(tree->base);
    free(tree->check);
    free(tree);
    return ;
}

int main() {
    int n, cnt1 = 1, cnt2;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    while (n--) {
        scanf("%s", str);
    }
    DATrie *tree = getDATrie(cnt1 * BASE + 5);
    build_DATrie(tree->root, root, tree);
    while (~scanf("%s", str)) {
        printf("search %s, result = %s\n", str, query(tree, str) ? "YES" : "No");
    }
    int mem1 = cnt1 *sizeof(Node), mem2 = cnt2 * sizeof(int) * 2 + sizeof(int) * 2;
    printf("Trie memory : %d bytes\n", mem1);
    printf("Double Array Trie memory : %d bytes\n", mem2);
    printf("memory rate: %.4lf\n", 1.0 * mem2 / mem1 * 100);
    clearDA(tree);
    clear(root);
    return 0;
}
