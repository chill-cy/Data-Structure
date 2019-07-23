/*************************************************************************
	> File Name: 102.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月21日 星期日 14时16分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Data {
    int dep, size, *depSize;
} Data;

Data *initData(struct TreeNode *root, Data *d1, Data *d2) {
    static Data initData = {0, 0, 0};
    if (root == NULL) return &initData;
    Data *d = (Data *)malloc(sizeof(Data));
    d->dep = fmax(d1->dep + d2->dep) + 1;
    d->size = d1->size + d2->size + 1;
    d->depSize = (int *)malloc(sizeof(int) * )
}
