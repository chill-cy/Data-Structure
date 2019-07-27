/*************************************************************************
	> File Name: 226.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月28日 星期日 00时17分13秒
 ************************************************************************/
//翻转树
#include<iostream>
using namespace std;

public TreeNode invertTree(TreeNode root) {
    if (root == null) return null;
    TreeNode left = root.left;
    root.left = invertTree(root.right);
    root.right = invertTree(left);
    return root;
}
