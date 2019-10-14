/*************************************************************************
	> File Name: 216.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 00时28分06秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name[105];
    char a[20];
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        name[i] = name[i].substr(3);//从第三位开始截取字符串
    }
    sort(name, name + n);
    for (int i = 0; i < n; i++) {
        cout << name[i] << endl;
    }
    return 0;
}
