/*************************************************************************
	> File Name: k.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月28日 星期六 18时43分08秒
 ************************************************************************/

#include<iostream>
using namespace std;

union Test {
    char a[4];
    int32_t b;
};

int main() {
    union Test test;
    test.a[0] = 256;
    test.a[1] = 255;
    test.a[2] = 254;
    test.a[3] = 253;
    printf("%d", test.b);
    return 0;
}
