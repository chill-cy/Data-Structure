/*************************************************************************
	> File Name: 178.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 14时17分25秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    char c = 'A';
    for (int i = 0, j = 0; i < n; i++, j += 2) {
        str[j] = 'A';
        c += 1;
        str[j + 1] = c;
        //cout << str[j] << " " << str[j + 1] << " ";
    }
    for (int i = 0; i < 2 * n; i++) {
        cout << str[i];
    }
    //cout << str << endl;
    for (int i = 2 * n - 2; i >= 0; i--) {
        cout << str[i];
    }
    //str = reserve(str);
   // cout << endl;
    //cout << str;
    //printf("%s\n", str);
    //int len = str.size() - 1;
    //cout << len << endl;
    //for (int i = len, j = len - 1; j >= 0; j--, i++) {
    //  str[i] = str[j];
      //  cout << str[i];
    //}
    //for (int i = 0; i < 2 * n; i++) {
    //    cout << str[i];
    //}
   // printf("%s\n", str);
    return 0;
}
