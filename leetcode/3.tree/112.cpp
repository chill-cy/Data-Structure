/*************************************************************************
	> File Name: 112.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 15时33分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool hasPathSum(struct TreeNode* root) {
    if (root == NULL) return false;
    if (root->left == 0 && root->right == NULL) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
