/*************************************************************************
	> File Name: 154.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 12时16分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            if (j != i) cout << " ";
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
