/*************************************************************************
	> File Name: 83.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月10日 星期三 21时54分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p = head, *q;
    while (p && p->next) {
        if (p->next->val == p->val) {
            q = p->next->next;
            free(p->next);
            p->next = q;
        } else {
            p = p->next;
        }
    }
    return head;
}

