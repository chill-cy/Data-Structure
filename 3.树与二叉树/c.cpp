/*************************************************************************
	> File Name: c.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月26日 星期四 18时28分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define min(a, b) ((a) < (b) ? (a) : (b))
//预编译器在预处理时会先计算处理，为了避免超界可以加上类型UL无符号长整形
#define second_per (365*24*60*60)UL

struct {
    short a1;
    short a2;
    short a3;
}A;

int main() {
    int b = 500;
    //sizeof操作符，可以用sizeof a，不可外部使用
    printf("%d\n", sizeof b);
    //cout << sizeof b << endl;
    //静态全局变量每一次使用都不变
    //static int b;
    //修饰a内容
    //const int *a = &b;
    //限定指针指向的内容不能变
    //int const *a = &b;
    //const *int a = &b;
    //printf("%d\n", a);
    //限定指针不能变
    //int *const a = &b;
    //指针和内容都不能变
    //const int* const a = &b;
    //int *const a;
    //a = &c;
    //const 有安全检查，define直接展开
    //char *ss1 = "0123456789";
    char q1[] = "a\n";
    //以最长的对齐
    class B {
        private:
        bool m_bTemp;
        int m_nTemp;
        bool m_bTemp2;
    };
    class C {
        private:
        
    };
    //cout << sizeof(B) << endl;
    //cout << sizeof(q1) << endl;
    //cout << sizeof(A) << endl;
    //printf("%d\n", sizeof(ss1));
    //printf("%d\n", *a);
    return 0;
}
