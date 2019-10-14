/*************************************************************************
	> File Name: 123.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 17时05分08秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a >= c && b <= d){
        printf("YES\n");
    } else if (a <= c && b >= d) {
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}
