/*************************************************************************
	> File Name: 234-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月15日 星期一 19时04分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isPalindrome(struct ListNode* head) {
    int n = getListLength(head);
    struct ListNode *p = getIndex(head, (n + 1) / 2);
    p = reverseList(p);
    while (head && p) {
        if (head)
    }
}
