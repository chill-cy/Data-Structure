/*************************************************************************
	> File Name: 172.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 11时32分55秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    string str[12];
    for (int i = 0; i < 10; i++) {
        cin >> str[i];
    }
    sort(str, str + 10);
    for (int i = 0; i < 10; i++) {
        cout << str[i] << endl;;
    }
    return 0;
}
