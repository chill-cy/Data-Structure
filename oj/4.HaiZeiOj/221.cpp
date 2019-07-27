/*************************************************************************
	> File Name: 221.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月11日 星期四 19时16分32秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_N 100000
struct num {
    int ind;
    int sum;
    int high;
};
struct num nums[MAX_N + 5];

int poll[MAX_N + 5];

bool cmp(num a, num b) {
    return a.high < b.high;
}

bool cmp1(num a, num b) {
    return a.ind < b.ind;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].high;
        nums[i].ind = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> poll[i];
    }
    sort(nums, nums + n, cmp);
    sort(poll, poll + m);
    //for (int i = 0; i < n; i++) {
      //  cout << nums[i].high << " : " << nums[i].ind << "  ";
    //}
    int start = 0, j;
    for (int i = 0; i < n; i++) {
        for (j = start; j < m; j++) {
            if (nums[i].high >= poll[j]) nums[i].sum++;
            else break;
        }
        start = j;
    }
    sort(nums, nums + n, cmp1);
    for (int i = 0; i < n; i++) {
        cout << nums[i].sum << endl;
    }
    return 0;
}
