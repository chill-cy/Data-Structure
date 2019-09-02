/*************************************************************************
	> File Name: 2.linklist-6.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月02日 星期一 20时41分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList {
    ListNode head;
    int length;
} LinkList;

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->length = 0;
    l->head.next = NULL;
    return l;
}

ListNode *init_listnode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
    return node;
}

void clear_listnode(ListNode *q) {
    if (q == NULL) return ;
    free(q);
    return ;
}

void clear_linklist(LinkList *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(l);
    return ;
}

int insert(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *q = &(l->head), *node = init_listnode(val);
    while (ind--) {
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    l->length += 1;
    return 1;
}

int erase (LinkList *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
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
    printf("LinkList (%d) = : ", l->length);
    for (ListNode *q = l->head.next; q; q = q->next) {
        printf("%d -> ", q->data);
    }
    printf("NULL\n");
    return ;
}
int main() {
    int val, ind, op;
    #define MAX_OP 30
    LinkList *l = init_linklist();
    for (int i = 0; i < MAX_OP; i++) {
        val = rand() % 100;
        ind = rand() % (l->length + 1);
        op = rand() % 3;
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
    }
    clear_linklist(l);
    return 0;
}
