/*************************************************************************
	> File Name: 171.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月19日 星期一 14时11分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

int get_num(char *str, int len) {
    int i = 0;
    while (i < len) {
        sum *= 10;
        sum += (str[i] - '0');
    }
}

int main() {
    char str[1000];
    cin >> str;
    int len = strlen(str);
    int i = 0;
    int sum = get_num(str, len / 2);
    return 0;
}
