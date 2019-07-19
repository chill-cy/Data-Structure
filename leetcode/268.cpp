/*************************************************************************
	> File Name: 268.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月15日 星期一 16时29分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

int missingNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != i && nums[i] != numsSize) {
            int a = nums[i], b = nums[i];
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] - i) return i;
    }
    return numsSize;
}
