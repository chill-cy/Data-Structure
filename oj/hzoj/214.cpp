/*************************************************************************
	> File Name: 214.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 00时03分38秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    double score[35];
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    sort(score, score + n, greater<int>());
    double k, sum = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        sum += score[i];
    }
    printf("%.2f\n", sum / k);
    return 0;
}
