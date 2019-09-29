/*************************************************************************
	> File Name: e.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月28日 星期六 15时12分10秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;struct S {
int i;
int *p;
};
int main() {
S s;
int *p = &s.i;
p[0] = 4;

    printf("%d, %d, %d , %d", sizeof(s), sizeof(s.i), sizeof(s.p));
p[1] = 3;
    printf("%d", p[1]);
s.p = p;
    printf("%d", s.p);
s.p[1] = 1;
s.p[0                                                                                                               iiin ] = 2;
return 0;
}
