/*************************************************************************
	> File Name: 203.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月15日 星期一 18时44分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode *p, *q, ret;
ret.next = head;
p = &ret;
while (p->next) {
    if (p->next->val == val) {
        q = p->next;
        p->next = p->next->next;
        free(q);
    } else {
        p = p->next;
    }
    return ret.next;
}
