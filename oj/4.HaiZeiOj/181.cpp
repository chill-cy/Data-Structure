/*************************************************************************
	> File Name: 181.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 17时52分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else {
            str[i] += 32;
        }
    }
    cout << str << endl;
    return 0;
}
