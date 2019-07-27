/*************************************************************************
	> File Name: 197.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 03时29分05秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[11] = {0};
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    sort(a, a + 10, greater<int>());
    for (int i = 0; i < 10; i++) {
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
