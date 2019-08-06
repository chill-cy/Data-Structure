/*************************************************************************
	> File Name: string.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月30日 星期二 20时48分11秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

int main() {
    /*
    string s = "abcdefg";
    string d(begin(s) + 2, begin(s) + 5);
    cout << d << endl;
    char k[] = "abcdefg";
    char b[4];
    strncpy(b, k + 2, 3);
    //b[3] = '\0';
    cout << b << endl;
    */ 
    string a = "abcdefg";
    a.replace(begin(a) + 2, begin(a) + 5, "XYZW");
    cout << a << endl;

    string b = "abcdefg";
    b.replace(begin(b) + 2, begin(b) + 5, "UV");
    cout << b << endl;

    return 0;
}
