/*************************************************************************
	> File Name: 2.linklist-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月13日 星期二 23时07分09秒
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList {
    ListNode head;//虚拟头结点
    int length
} LinkList;

ListNode *init_listnode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head = NULL;
    l->length = 0;
    return l;
}

void clear_listnode(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_linklist(LinkList *l) {
    if (l == NULL) return ;
    //顺着链表销毁结点
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(l);
    return ;
}


//在ind插入val
int insert(LinkList *l, int ind, int val) {
    //没有这个链表
    if (l == NULL) return 0;
    //插入位置不合法
    if (ind < 0 || ind > l->length) return 0;
    //虚拟头结点指向第０位,向第i位插入指针p初始指向头结点走i步可以指向待插入位置的前一个位置
    ListNode *p = &(l->head), *node = init_listnode(val);
    while (ind--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return l;
}

int erase(LinkList *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    LinkNode *p = &(l->head), *q;
    while (ind--) {
        p = p->next;
    }
    q = p->next->next;
    clear_listnode(p->next);
    p->next = q;
    l->length -= 1;
    return 1;
}

void output(LinkList *l) {
    printf("LinkList(%d) : ", l->length);
    for (LinkNode *p = l->head.next; p; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    LinkList *l = init_listnode();
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 3;
        //返回从０到l->length;
        int ind = rand() % (l->length + 1);
        int val = rand() % 100;
        switch(op) {
            case 0:
            case 1: {
                printf("insert %d at %d to LinkList = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("erase item at %d from LinkList = %d\n", ind, erase(l, ind));
            } break;
        }
        output(l);
        printf("\n");
    }
    clear_listnode(l);
    return 0;
}
