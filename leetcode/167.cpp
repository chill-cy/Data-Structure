/*************************************************************************
	> File Name: 167.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月20日 星期六 14时35分01秒
 ************************************************************************/

//在有序数组中找出两个数，使他们的和为target
//使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
//*如果两个指针指向元素的和sum == target,那么得到要求的结果；
//*如果sum > target,移动较大的元素，使sum变小一些
//*如果sum < target,移动较小的元素，使sum变大一些

#include<iostream>
using namespace std;

public int[] twoSum(int[] numbers, int target) {
    int i = 0, j = numbers.length - 1;
    while (i < j) {
        int sum = numbers.length - 1;
        if (sum == target) {
            return new int[]{i + 1, j + 1};
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return null;
}
