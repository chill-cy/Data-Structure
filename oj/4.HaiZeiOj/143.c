/*************************************************************************
	> File Name: 143.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 23时45分23秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int is_prime(int i) {
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) return 0;
    }
    return 1;
}
int is_square(int i) {
    int a = sqrt(i);//sqrt返回值为double类型
    if(i == a * a) return 1;
    return 0;
}
int main() {
    int a, b;
    cin >> a >> b;
    int flag = 0;
    int total = 0;
    for (int i = a; i <= b; i++) {
        if (i % 6 == 0) {
            int A = i / 100;
            int C = i % 100;
            if (is_prime(A) && is_square(C)) {
                if (flag == 0) {
                    flag = 1;
                    printf("%d", i);
                    total++;
                    continue;
                }
                printf(" %d", i);
                total++;
            }
        }
    }
    cout << endl;
    cout << total << endl;
    return 0;
}
