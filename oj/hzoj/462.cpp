/*************************************************************************
	> File Name: 462.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月11日 星期日 18时21分13秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

#define MAX_N 10000

int main() {
    int n;
    char type;
    char id_num[MAX_N + 5][20] = {0};
    int q_num[MAX_N + 5] = {0};
    cin >> n;
    int cnt = 0;
    long long int sum = 0;
    int boy = 0, girl = 0;
    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == 'i') {
            cin >> id_num[i];
            int len = strlen(id_num[i]);
            if ((id_num[i][len - 2] - '0') % 2 == 0) {
                girl += 1;            
            } else {
                boy += 1;
            }
        }
        if (type == 'q') {
            cin >> q_num[i];
            cnt += 1;
            sum += q_num[i];
        }
    }
    long long int aver = sum / cnt;
    if (cnt == 0) {
        aver = 0;
    }
    cout << boy << " " << girl << " " << aver << endl;
    return 0;
}
