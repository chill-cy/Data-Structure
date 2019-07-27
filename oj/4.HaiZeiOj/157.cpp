/*************************************************************************
	> File Name: 157.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月01日 星期一 00时44分32秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = n - i; j <= n - 1; j++) {
            cout << " ";
        }
        for (int j = i; j < n; j++) {
            printf("%c", a);
            a += 1;
        }
        a -= 2;
        for (int j = n - i - 1; j > 0; j--) {
            printf("%c", a);
            a -= 1;
        }
        a += 2;
        cout << endl;
    }
    a -= 2;
    //printf("%c", a);
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - i - 3; j >= 0; j--) {
            cout << " ";
        }
        for (int j = 0; j < i + 2; j++) {
            printf("%c", a);
            a += 1;
        }
        a -= 2;
        for (int j = 0; j < i + 1; j++) {
            printf("%c", a);
            a -= 1;
        }
    
        cout << endl;
    }
    return 0;
}
