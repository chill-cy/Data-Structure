/*************************************************************************
	> File Name: 234.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月12日 星期五 23时33分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

//从中间结点的下一元素开始翻转
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *p, *q, ret;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
//求总长度
int getListLength(struct ListNode *head) {
    int ret = 0;
    while (head) ++ret, head = head->next;
    return ret;
}
//获得中间结点的下一个元素的地址
struct ListNode *getIndex(struct ListNode *head, int ind) {
    struct ListNode *p = head;
    while (ind) p = p->next, ind--;
    return p;
}

bool isPalindrome(struct ListNode* head) {
    int n = getListLength(head);
    struct ListNode *p = getIndex(head, (n + 1) / 2);
    p = reverseList(p);
    while (head && p) {
        if (head->val - p->val) return false;
        head = head->next;
        p = p->next;
    }
    return true;
}

