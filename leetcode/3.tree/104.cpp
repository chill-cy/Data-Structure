/*************************************************************************
	> File Name: 104.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 14时29分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int d1 = maxDepth(root->left);
    int d2 = maxDepth(root->right);
    return fmax(d1, d2) + 1;
}
