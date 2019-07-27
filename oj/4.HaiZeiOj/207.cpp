/*************************************************************************
	> File Name: 207.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 22时10分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name[35];
    int score[5];
    int j = 0;
    int sum[35] = {0};
    string max_name;
    int max_score = 0, min_score = 101;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        for (j = 0; j < 4; j++) {
            cin >> score[j];
            if(max_score < score[j]) max_score = score[j];
            if(min_score > score[j]) min_score = score[j];
            sum[i] += score[j];
        }
        if (sum[i] > max) {
            max = sum[i];
            max_name = name[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sum[i] << endl;
    }
    cout << max_name << endl;
    cout << max_score << " " << min_score << endl;
    return 0;
}
