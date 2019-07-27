/*************************************************************************
	> File Name: 完美的宏定义.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月01日 星期一 13时25分31秒
 ************************************************************************/

#include <stdlib.h>

#define MAX(a, b) (a) > (b) ? (a) : (b) 

#define Plog(frm, arg...) {\
    printf("[ $funcname : $lineno ] $user");\
}

void haizei_test() {
    int a = 6;
    Plog("%d", MAX(2, 3));
    Plog("%d", 5 + MAX(2, 3));
    Plog("%d", MAX(2, MAX(3, 4)));
    Plog("%d", MAX(2, 3 > 4 ? 3 : 4));
    Plog("%d", MAX(a++, 6));
    Plog("a value = %d", a);
}

int main() {
    haizei_test();
    return 0;
}

