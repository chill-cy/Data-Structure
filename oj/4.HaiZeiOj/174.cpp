/*************************************************************************
	> File Name: 174.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 11时53分14秒
 ************************************************************************/

#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    while (str.find(' ') != -1) {
        int pos = str.find(' ');
        str = str.replace(pos, 1, "%20");
    }
    cout << str;
    return 0;
}
