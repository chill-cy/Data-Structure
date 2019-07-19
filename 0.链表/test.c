/*************************************************************************
	> File Name: test.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月10日 星期三 10时15分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList {
    ListNode head;//虚拟头结点
    int length;
} LinkList;

ListNode *init_listnode (int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;//虚拟头结点的下一位指向空，每次向虚拟头结点的后面插入，虚拟头结点的下一位算是第０位，
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
    ListNode *p = l->head.next, *q;//p应该指向链表中的第一个有值结点，也就是虚拟头结点的下一个结点
    while(p) {
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
    ListNode *p = &(l->head), *node = init_listnode(val);//p初始指向虚拟头结点的地址, node指向新生成的链表结点
    while (ind--) {//p最终指向待插入结点的前一个位置
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(LinkList *l, int ind) {
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
    printf ("LinkList(%d): ", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d-> ", p->data);
    }
    printf(("NULL\n"));
    return ;
}

#define MAX_OP 30

int main() {
    srand(time(0));
    LinkList *l = init_linklist();
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 3;
        int ind = rand() % (l->length + 1);
        int val = rand() % 100;
        switch (op) {
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
    clear_linklist(l);
    return 0;
}
