/*************************************************************************
	> File Name: 215.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 00时13分55秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name[45];
    int score[5];
    string rank[1000];
    int rank_score[45];
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            cin >> score[i];
            sum += score[i];
        }
        rank_score[i] = sum;
        rank[sum] = name[i];
    }
    sort(rank_score, rank_score + n, greater<int>());
    for (int i = 0; i < 3; i++) {
        cout << rank[rank_score[i]] << endl;
    }
    return 0;
}
