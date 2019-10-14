/*************************************************************************
	> File Name: 177.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 12时38分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    char str1[3];
    cout << str << endl;
    for (int i = 1; i < str.size(); i++) {
        str1[0] = str[str.size() - 2];
        str1[1] = str[str.size() - 1];
        //ar c = str[str.size() - 3];
        for (int k = str.size() - 3, j = str.size() - 1; j >= 2; k--, j--) {
            str[j] = str[k];
        }
        //r[str.size() - 1] = c;
        str[0] = str1[0];
        str[1] = str1[1];
        cout << str << endl;
    }
    return 0;
}
