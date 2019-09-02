/*************************************************************************
	> File Name: lc_1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月19日 星期一 15时36分12秒
 ************************************************************************/

#include<iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct Ind_num {
    int num;
    int ind;
};

typedef pair<int, int> PII;

bool cmp (struct Ind_num &a, struct Ind_num &b) {
    if (a.ind == b.ind) return a.num < b.num;
    return a.num < b.num;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    struct Ind_num *number = (struct Ind_num *)malloc(sizeof(struct Ind_num) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        number[i].num = nums[i];
        number[i].ind = i;
    }
    sort(number, number + numsSize, cmp);
    int *ind = (int *)malloc(sizeof(int) * 3);
    for (int i = 0, j = numsSize - 1; i < j;) {
        if (number[i].num + number[j].num == target) {
            ind[0] = number[i].ind;
            ind[1] = number[j].ind;
            //cout << "i = " << number[i].ind <<" "<< number[i].num << "     j = " << number[j].ind << " " << number[j].num << endl;
            return ind;
        }
        if (number[i].num + number[j].num < target) i++;
        if (number[i].num + number[j].num > target) j--;
    }
    free(ind);
    return 0;
}

int main() {
    int nums[1000], n, target;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;
    int size;
    int *ind = twoSum(nums, n, target, &size);
    cout << ind[0] << " " << ind[1] << endl;
    return 0;
}
