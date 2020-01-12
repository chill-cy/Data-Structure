/*************************************************************************
	> File Name: test.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月17日 星期四 18时04分40秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 1000000
int val[MAX_N + 5];
char str[MAX_N + 5];
int dp[MAX_N + 5][3];

int main() {
    cin >> (str + 1);
    for (int i = 1; str[i]; i++) cin >> val[i];
    for (int i = 1; str[i]; i++) {
        dp[i][0] = dp[i - 1][0] + val[i] + (str[i] == 'a');
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + val[i] * (str[i] == 'c'));
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2] + val[i] * (str[i] == 'm'));
    }
    int len = strlen(str);
    cout << dp[0][2];
    return 0; 
}
