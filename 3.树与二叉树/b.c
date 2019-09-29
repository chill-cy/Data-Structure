/*************************************************************************
	> File Name: b.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月28日 星期六 14时38分58秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
void GetMemory(char **p, int num) {
*p = (char *)malloc(sizeof(char) * num);
}

char *strA() {
    char str[] = "Hello world";
    return str;
}

char *strB() {
    char *str = "hello world";
    //char *str = (char *)malloc(sizeof(char));
    //strcpy(str, "Hello world");
    //str = "Hello world";
    return str;
}
int main() {

    cout << *strA() << endl;
    cout << *strB() << endl;

    return 0;
}

