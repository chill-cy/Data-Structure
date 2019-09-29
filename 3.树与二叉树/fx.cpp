/*************************************************************************
	> File Name: fx.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月28日 星期六 14时15分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

int fun(int x) {
    return x + 1;
}

void fun(int *x) {
    (*x) = (*x) + 1;
} 

void fun3(int &x) {
    x = x + 1;
}

int main() {
    int x = 1;
    //cout << fun1(x) << endl;
    int *pi;
    *pi = 5;

    pi = &iv3;
    return 0;
}
