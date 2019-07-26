/*************************************************************************
	> File Name: 6.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月26日 星期五 20时39分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

//交换两表中的相邻结点

public ListNode swapPairs(ListNode head) {
    ListNode node = new ListNode(-1);
    node.next = head;
    ListNode pre = node;
    while (pre.next != null && pre.next.next != null) {
        ListNode l1 = pre.next, l2 = pre.next.next;
        ListNode next = l2.next;
        l1.next = next;
        l2.next = l1;
        pre.next = l2;
        pre = l1;
    }

    return node.next;
}
