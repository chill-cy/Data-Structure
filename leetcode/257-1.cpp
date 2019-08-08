/*************************************************************************
	> File Name: 257-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月07日 星期三 21时31分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt = getResult(root->left, len, k, ret, buff);
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
    int pathCnt = getPathCnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 10000;
    char *buff = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buff);
    free(buff);
    *returnSize = pathCnt;
    return ret;
}

int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    //到叶子结点将一条路径结果存入ret[k]
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    }
    //没到叶子节点，将指向下一节点的箭头存入buff，
    len += sprintf(buff + len, "->");
    //递归遍历左子树的路径数
    int cnt = getResult(root->left, len, k, ret, buff);
    //递归遍历右子树的路径数
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
    int pathCnt = getPathCnt(root);//获取树高
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);//存储每条字符串
    int max_len = 10000;//最大字符串上限
    char *buff = (char **)malloc(sizeof(char) * max_len);//存储一条路径
    getResult(root, 0, 0, ret, buff);
    free(buff);
    *returnSize = pathCnt;
    return ret;
}



int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt = getResult(root->left, len, k, ret, buff);
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
    int pathCnt = getPathCnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 10000;
    char *buff = (char **)malloc(sizeof(char) * max_len);
    getPathCnt(root, 0, 0, ret, buff);
    free(buff);
    *returnSize = pathCnt;
    return ret;
}


int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    
}

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = key;
    p->ltag = p->rtag = NORMAL;
    return p;
}

void heap_sort(int )
