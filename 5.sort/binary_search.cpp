/*************************************************************************
	> File Name: binary_search.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月14日 星期三 15时43分42秒
 ************************************************************************/

#include <stdio.h>

int binary_search(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    //<=是因为找到等与x的元素的下标
    while(head <= tail) {
        mid = (head + tail) >> 2;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//前１后０
int binary_search1(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    //找到最后一个与１的位置,待查找区间只有一个元素即找到了最后一个１
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) head = mid;
        
    }
} 

int binary_search2(int )

int main() {
    
    return 0;
}
