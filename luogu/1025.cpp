/*************************************************************************
	> File Name: 1025.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月07日 星期日 09时47分38秒
 ************************************************************************/

#include <stdio.h>

int f(int n, int k) {
    if (k == 1) return 1;
    if (n < k) return 0;
    if (n == k) return 1;
    if (n > k) return f(n - 1, k - 1) + f(n - k, k); 
}

int main() {
    int n, k;
    scanf("%d%d",&n, &k);
    int sum = f(n, k);
    printf("%d\n", sum);
    return 0;
}
