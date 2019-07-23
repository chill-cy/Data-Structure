/*************************************************************************
	> File Name: 88.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月20日 星期六 15时28分59秒
 ************************************************************************/

//归并两个有序数组
//把归并结果存在第一个数组上，否则在nums1上归并得到的值会覆盖还未进行归并比较的值

#include<iostream>
using namespace std;

public void merge(int[] nums1, int m, int[] nums2, int n) {
    int index1 = m - 1, index2 = n - 1;
    int indexMerge = m + n - 1;
    while (index1 >= 0 || index2 >= 0) {
        if (index1 < 0) {
            nums1[indexMerge--] = nums2[index2--];
        } else if (index2 < 0) {
            nums1[indexMerge--] = nums1[index1--]
        } else if (nums1[index1] > nums2[index2]){
            nums1[indexMerge--] = nums1[index1--];
        } else {
            nums1[indexMerge--] = nums2[index2--];
        }
    }
}
