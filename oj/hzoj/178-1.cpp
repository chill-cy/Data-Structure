/*************************************************************************
	> File Name: 178-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 15时55分00秒
 ************************************************************************/

#include<iostream>
#include <cstring>

using namespace std;
#define MAX_N 1000000
int main() {
    int n;
    cin >> n;
    char str[MAX_N + 5] = {'A'};
    for (int i = 1; i < n; i++) {
        int len = strlen(str);
        cout << len << endl;
        for (int j = 0, k = 2 * len; j < len; j++, k--) {
            str[k] = str[j];
        }
        str[len] = 'A' + i;
    }
    cout << str << endl;
    return 0;
}
