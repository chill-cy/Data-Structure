/*************************************************************************
	> File Name: 19.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月10日 星期三 18时49分17秒
 ************************************************************************/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret, *p = &ret, *q = head;
    ret.next = head;
    while(n--) q = q->next;
    while(q) q = q->next, p = p->next;
    q = p->next->next;
    free(p->next);
    p->next = q;
    return ret.next;
}
