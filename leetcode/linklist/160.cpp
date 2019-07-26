/*************************************************************************
	> File Name: 160.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月10日 星期三 23时04分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   struct ListNode *p = headA, *q = headB, *a, *b;
    a = p, b = q;
    do {
        p = p->next;
        q = q->next;
        if (p == NULL) p = b;
        if (q == NULL) q = a;
        if (p == q) {
            printf("Reference of the node with value = %d", p->val);
            break;
        }
    } while (p != q);
    printf("null");
}

public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    ListNode l1 = headA, l2 = headB;
    while (l1 != l2) {
        l1 = (l1 == null) ? headB : l1.next;
        l2 = (l2 == null) ? headA : l2.next;
    }
    return l1;
}
