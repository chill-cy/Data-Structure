/*************************************************************************
	> File Name: 12.double_array_trie-5.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月11日 星期五 16时39分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

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

Node *getNewNode() {
    Node *root = (Node *)calloc(sizeof(Node), 1);
    return root;
}

DATrie *getNewDATrie(int n) {
    DATrie *tree = (DATrie *)calloc(sizeof(DATrie), 1);
    tree->size = n;
    tree->root = 1;
    tree->base = (int *)calloc(sizeo(int), n);
    tree->check = (int *)calloc(sizeof(int), n);
    tree->check[tree->root] = 1;
    return tree;
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

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), cnt +=1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == 0) p->next[ind] = getNewNode(), cnt += 1;
        p = p->next[ind];
    }
    p->flag = 1;
    return cnt;
}


int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    //将所有子结点的父节点编号设置为当前结点ind
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    return ans;
}


int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    return ans;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue();
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    return ans;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue();
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    return ans;
}


int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue();
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    return ans;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue();
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    return ans;
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
    } while (!flag);
    return base;
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
    } while (!flag);
    return base;
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
    } while(!flag);
    return base;
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
    } while(!flag);
    return base;
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
    } while(!flag);
    return base;
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 0, flag;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 0, flag;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }             
    } while (!flag);
    return base;
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
    } while (!flag);
    return base;
}

int getBaseValue(Node *root, DATrie *tree) {
    int base = 0, flag;
    do {
        base += 1;
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (tree->check[base + i] == 0) continue;
            flag = 0;
            break;
        }
    } while (!flag);
    return base;
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
    } while (!flag);
    return base;
}

int query(DATrie *tree, const char *str) {
    int p = tree->root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (abs(tree->check[tree->base[p] + ind]) != p) return 0;
        p = tree->base[p] + ind;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return tree->check[p] < 0;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

int buildDATrie(int ind, Node *root, DATrie *tree) {
    int base = tree->base[ind] = getBaseValue(root, tree);
    int ans = ind;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        tree->check[base + i] = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        int temp = buildDATrie(base + i, root->next[i], tree);
        if (temp > ans) ans = temp;
    }
    if (root->flag) tree->check[ind] = -tree->check[ind];
    return ans;
}

void clear(Node *root) {
    if (root == NULL) return root;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
} 

void clearDA(Node *tree) {
    if (tree == NULL) return;
    free(tree->check);
    free(tree->base);
    free(tree);
    return ;
}
int main() {
    int n, cnt1 = 1, cnt2;
    char str[100];
    scanf("%d", &n);
    Node *
    return 0;
}
