/*************************************************************************
	> File Name: 159.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月02日 星期二 10时11分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    int n = (int)(c - 'A') + 1;
   // cout << n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << c;
            c--;
        }

        for (int j = 1; j < n - i; j++) {
            c++;
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
