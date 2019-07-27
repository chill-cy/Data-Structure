/*************************************************************************
	> File Name: 141_1.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 20时43分20秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a = 'A';
    char c = 'A';
    for (int i = 1; i <= n + 1; i++) {
        for (int k = 1; k <= i - 1; k++) {
            if (i == 1) continue;
            else cout << " ";
        }
        for (int j = n - i + 2; j >= 1; j--) {
            printf("%c", a);
            a += 1;
            if (j == 1) a -= 1;
        }
        a -= 1;
        for (int j = n - i + 1; j >= 1; j--) {
            //if (j == n - i + 1) a -= 1;
            printf("%c", a);
            a -= 1;
        }
        a += 2;
        cout << endl;
    }
    a -= 2;
    for (int i = 1; i <= n; i++) {
        for (int k = n - i; k >= 1; k--) {
            cout << " ";
        }
        for (int j = 1; j <= i + 1; j++) {
            printf ("%c", a);
            a += 1;
        }
        a -= 2;
        for (int j = 1; j <= i; j++) {
            printf("%c", a);
            a -= 1;
        }
        cout << endl;
    }
    return 0;
}
