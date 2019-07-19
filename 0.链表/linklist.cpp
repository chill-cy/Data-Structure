/*************************************************************************
	> File Name: linklist.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月06日 星期六 00时12分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LinkNode {//定义链表结点
    int data;//数据域
    struct LinkNode *next;//指向下一个链表结点的指针
} LinkNode;

typedef struct LinkList {//定义链表
    LinkNode head;//表头结点
    int length;//链表长度
} LinkList;

LinkList *init() {//初始化链表
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));     //初始化一个指向链表的指针
    p->head.next = NULL;       //头指针指向头结点，头结点next域初始化为空
    p->length = 0;             //链表长度为空
    return p;                  //返回头指针
}

LinkNode *getNewNode(int value) {//初始化链表结点
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));       //初始化指向表结点的指针类型p
    p->data = value;                  //data域初始化存入value值
    p->next = NULL;                   //next域初始化为空
    return p;                         //返回结点指针p
}

void insert(LinkList *l, int value, int ind) {//在ind位置插入值为value的元素
    LinkNode *p = &(l->head);  //p指向头结点的地址
    while (ind--) {            //找到待插入位置前一个位置
        p = p->next;           //p后移
        if (p == NULL) return ;    //插入位置前的元素为空时非法
    }
    LinkNode *new_node = getNewNode(value);      //申请一个新的表结点，定义一个表结点指向它
    new_node->next = p->next;             //新结点指针指向待插入位置的结点
    p->next = new_node;                   //待插入位置前的结点next域指向新结点
    l->length += 1;
    return ;
}

void erase (LinkList *l, int ind) {       //删除ind位置的元素
    LinkNode *p = &(l->head);             //p指向表头节点的地址
    while (ind--) {                  //找到待删除位置前一个位置
        p = p->next;                 //p后移
        if (p == NULL) return ;     //若待删除位置前的元素为空时删除操作非法
    }
    if (p->next == NULL) return ;      //待删位置为空时删除操作非法
    LinkNode *q = p->next;             //q指向待删除位置的结点
    p->next = p->next->next;           //删除待删位置元素
    free(q);                           //释放待删位置所占空间
    l->length -= 1;                    //执行完删除操作链表长度减少
    return ;
}

void clear(LinkList *l) {                 //清空指针l所指向的链表
    if (l->head.next == NULL) return ;    //链表为空直接返回不做清空操作
    LinkNode *p = l->head.next, *q;       //p指向链表第一个元素，
    while (p) {                   //循环删除
        q = p;                    //q指向待删节点
        p = p->next;              //p指针循环后移
        free(q);                  //释放待删结点所占空间
    }
    free(l);                     //释放链表头结点所占空间　　　
    return ;
}

void output(LinkList *l) {            // 输出链表l
    printf("[%d]", l->length);        //  输出表长
    LinkNode *p = l->head.next;       //p指向待输出的第一个元素
    while (p != NULL) {               //带输出元素不空
        printf("%d->", p->data);      //输出表结点的值
        p = p->next;                  // 指针后移
    }
    printf("NULL\n");                //p最后指向为空
    return ;
}

int main() {
    srand(time(0)); 
    LinkList *l = init();             //初始化链表
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {     // 做MAX_OP次操作
        int op = rand() % 4, value, ind;     //有75%进行插入操作，25%的概率进行删除操作
        switch (op) {
            case 0:
            case 1:
            case 2: {             //插入元素
                ind = rand() % (l->length + 1);            //随机生成length+1以内的待插入位置
                value = rand() % 100;                      //随机生成100以内的待插入值
                printf("insert(%d, %d) to LinkList\n", value, ind); //输出值为value的元素插入ind位置
                insert(l, value, ind);
                output(l);                                 //输出插入元素后的链表：
            } break;
            case 3: {
                if (l->length == 0) break;                  //链表长度为０，没有可删元素
                ind = rand() % l->length;                   //随机生成length以内待删位置
                printf("erase(%d) from LinkList\n", ind);   //输出从链表中删除ind位置元素
                erase(l, ind);
                output(l);                                  //输出删除元素后的链表
            } break;
        }
    }
    clear(l);                //操作结束清空链表
    return 0;
}
