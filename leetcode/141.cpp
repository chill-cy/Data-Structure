/*************************************************************************
	> File Name: 141.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月10日 星期三 22时46分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if (p == NULL) return false;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return false;
        q = q->next;
    }
    return true;
}
