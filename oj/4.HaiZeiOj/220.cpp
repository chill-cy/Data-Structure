/*************************************************************************
	> File Name: 220.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 11时46分12秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name[105];
    int score[105][4];
    int sum[105];//第i个人成绩和
    string rang_sum[405] = {0};
    int ans[4] = {0};//每科最高分；
    int 
    int j;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        for (j = 0; j < 4; j++) {
            cin >> score[i][j];
            sum[i] += score[i][j];
        }

        rang_sum[sum[i]] = name[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            if (score[i][j] > ans[i]) {
                ans[i] = score[i][j];
            }
        }
    }
    sort(sum, sum + n, greater<int>());
    for (int i = 0; i < 4; i++) {
        cout << rang_sum[sum[i]] << endl;
    }
    return 0;
}
