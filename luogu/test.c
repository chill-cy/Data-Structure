/*************************************************************************
	> File Name: 1290.欧几里得.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年04月30日 星期二 15时14分51秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

void swap(int64_t *a, int64_t *b) {
    int64_t temp = *a;
    *a = *b;
    *b = temp; 
}

int main() {
    int32_t c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int64_t a, b;
        scanf("%I64d%I64d", a, b);
        if (a < b) {
            swap(&a, &b);
        }
        if (a / b > 1) {
            printf("Stan wins\n");
        }
        int32_t turn = 1;
        while (a / b == 1 && a % b != 0) {
            a %= b;
            if (a < b) {
                swap (&a , &b);
                turn = 0 - turn;
            }
        }
        if (turn == 1) {
            printf("Stan wins\n");
        } else {
            printf("Ollie wins\n");
        }
    }
    return 0;
}
