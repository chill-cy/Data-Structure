/*************************************************************************
	> File Name: 114.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月25日 星期二 17时30分31秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char x;
    scanf("%c", &x);
    char Name[10][10] = {"He", "Li", "Cao", "Duan", "Wang", "Not Here"};
    if (x == 'h') {
        cout << Name[0] << endl;
    } else if (x == 'l') {
        cout << Name[1] << endl;
    } else if (x == 'c') {
        cout << Name[2] << endl;
    } else if (x == 'd') {
        cout << Name[3] << endl;
    } else if (x == 'w') {
        cout << Name[4] << endl;
    } else {
        cout << Name[5] << endl;
    }
    return 0;
}
