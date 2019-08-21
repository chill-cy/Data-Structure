/*************************************************************************
	> File Name: 19.ac.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月21日 星期三 13时18分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define BASE 26

#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail;
} Node;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode(), ++cnt;
        p = p->next[ind];
    }

    p->flag = 1;
    return cnt;
} 

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

void build_ac(Node *root, n) {
    
}

int main() {
    Node *root = getNewNode();
    int n;
    char str[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    //build ac
    scanf("%s", str);
}
