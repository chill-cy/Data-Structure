/*************************************************************************
	> File Name: a.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月19日 星期六 05时21分05秒
 ************************************************************************/

#include<iostream>
#include <cstring>

using namespace std;

int main() {
    char a[100];
    cin >> a;
    char *p, *q;
    int len = strlen(a);
    int flag = 0;
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (a[i] == a[j]) continue;
        else {
            flag = 1;
            cout << "false" << endl;
            break;
        }
    } 
    if (!flag) cout << "true" << endl;

    return 0;
}
