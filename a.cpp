/*************************************************************************
	> File Name: a.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月18日 星期五 01时04分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    char str[100];
    cin >> str;
    int max = 0, ans = 0;
    for (int i = 1; str[i]; i++) {
        if (str[i] == str[i - 1] + 1) ans += 1;
        if (ans > max) max = ans;
        ans = 0;
    }
    cout << max << endl;
    return 0;
}
