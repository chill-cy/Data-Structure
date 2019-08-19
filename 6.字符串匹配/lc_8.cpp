/*************************************************************************
	> File Name: lc_8.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月19日 星期一 10时40分40秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;
#define MAX_N 2147483647
#define MIN_N -2147483648
int myAtoi(char *str) {
    int len = strlen(str);
    char flag = '+';
    long long sum = 0;
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+' && str[0] != ' ') return 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '-') flag = '-';
        if (str[i] - '0' <= 9 && str[i] - '0' >= 0) {
            sum *= 10;
            sum += (str[i] - '0');
        } 
        if (-sum <= MIN_N) return MIN_N;
        if (sum >= MAX_N) return MAX_N;
    }
    if (flag == '+') return sum;
    return -sum;
}

int main() {
    char str[1000] = {0};
    scanf("%[^\n]s", str);
    cout << mvAtoi(str) << endl;
    return 0;
}
