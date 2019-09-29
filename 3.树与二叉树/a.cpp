/*************************************************************************
	> File Name: a.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月26日 星期四 18时22分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define SUB(x,y) (x-y)
#define ACCESS_BEFORE(element, offset, value) *SUB(&element, offset)=value
int main() {
    int i;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ACCESS_BEFORE(array[5], 4, 6);
    for (int i = 0; i < 10; ++i) {
        printf("%d", array[i]);
    }
    return 0; 
     
}
