/*************************************************************************
	> File Name: 170-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 10时08分05秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    string p;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        while (str.find("Ban_smoking") != -1) {//查找一定范围内元素的个数
            int pos = str.find("Ban_smoking");//返回字符串在整个字符串中的位置
            str.replace(pos, 11, "No_smoking");
        }
        if (i == 0) cout << endl;
        cout << str << endl;
    }
    return 0;
}
