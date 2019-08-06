/*************************************************************************
	> File Name: vector.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月30日 星期二 16时46分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    vector<int> a(10);
    vector<int> b(10, 0);
    vector<int> c = {1, 10, 8, 4, 5};
    //int x = c[2];
    //c[3] = x;
    int sum = 0;
    for(auto x : a) {
        sum += x;
        printf("%d ", x);
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
