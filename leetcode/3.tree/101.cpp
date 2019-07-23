/*************************************************************************
	> File Name: 101.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 14时11分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isSymmetric(struct  TreeNode* root) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL && q == NULL) return false;
    if (p->val - q->val) return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isSameTree(root->left, root->right);
}
