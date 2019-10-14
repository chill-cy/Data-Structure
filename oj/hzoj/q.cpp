/*************************************************************************
	> File Name: q.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 18时55分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a % b) {
          printf("NO\n");
    } else printf("YES\n");
    return 0;
}
