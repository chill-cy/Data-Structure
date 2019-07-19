/*************************************************************************
	> File Name: 206.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月15日 星期一 18时49分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p, *q, ret;
    ret.next = NULL;
    p = head;
    while(p) {
        q = p->next;
        p->next = ret.next;

    }
}
