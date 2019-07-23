/*************************************************************************
	> File Name: 100.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 14时07分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL && q == NULL) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
