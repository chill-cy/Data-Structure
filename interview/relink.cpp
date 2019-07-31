/*************************************************************************
	> File Name: relink.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月28日 星期日 00时24分41秒
 ************************************************************************/
//单链表逆序输出
#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
    node(int d):data(d), next(NULL) {}
}node;

void reverse(node* head) {
    if (head == NULL || head->next == NULL) {
        return ;
    }
    node *prev = NULL;
    node *pcur = head->next;
    node *next;
    while (pcur != NULL) {
        if (pcur->next == NULL) {
            pcur->next = prev;
            break;
        }
        next = pcur->next;
        pcur->next = prev;
        prev = pcur;
        pcur = next;
    }
    head->next = pcur;
    node *tmp = head->next;
    while (tmp != NULL) {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
}

