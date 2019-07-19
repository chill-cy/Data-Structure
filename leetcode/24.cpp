/*************************************************************************
	> File Name: 24.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月10日 星期三 20时48分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ret, *p = &ret, *q = head;
    ret.next = head;
    while (q && q->next) {
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
}
