/*************************************************************************
	> File Name: 21.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月11日 星期日 00时04分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
public ListNode megeTwoLists(ListNode l1, ListNode l2) {
    if (l1 == null) return l2;
    if (l2 == null) return l1;
    if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = megeTwoLists(l1, l2.next);
        return l2;
    }
}
