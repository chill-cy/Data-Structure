/*************************************************************************
	> File Name: 107.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 14时23分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int **leveOrderBottom(struct TreeNode* root, int **columnSizes, int* returnSize) {
    if (root == NULL) return NULL;
    int n = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * n);
    int *size = (int *)calloc(sizeof(int), n);
    getSize(root, n - 1, size);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * size[i]);
        size[i] = 0;
    }
    getData(root, ret, size, n - 1);
    *returnSize = n;
    *columnSizes = size;
    return ret;
}


