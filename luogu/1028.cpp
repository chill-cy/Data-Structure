/*************************************************************************
	> File Name: 1028.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月07日 星期日 10时45分10秒
 ************************************************************************/
#include <stdio.h>
#define MAX_N 1000

int ans[MAX_N + 5] = {0};

int f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (ans[n]) return ans[n];
    int temp = 0;
    if (n % 2 == 1) 
        temp = f(n - 1);
    else 
        temp = f(n - 1) + f(n / 2);
    ans[n] = temp;
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int sum = f(n);
    printf("%d\n", sum);
    return 0;
}mZ
