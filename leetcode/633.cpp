/*************************************************************************
	> File Name: 633.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月20日 星期六 15时01分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

public boolean judgeSquareSum(int c) {
    int i = 0, j = (int)Math.sqrt(c);
    while(i <= j) {
        int powSum = i * i + j * j;
        if (powSum == c) {
            return true;
        } else if (powSum > c) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}
