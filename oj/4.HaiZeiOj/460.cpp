/*************************************************************************
	> File Name: 460.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月11日 星期日 19时22分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 1000

int main() {
    int n, k;
    cin >> n >> k;
    int a[MAX_N + 5] = {0};
    int i = 1;
    int flag = 0;
    int m = n;
    while (n > 1) {
        if (i == 1 && !flag) {
            if (i == 0) i += 1;
            i = k % (n + 1);
            //printf("i == %d\n", i);
            if (i == 0) i += 1;
            p = i;
            while (a[p]) {
                if (a[p] == 0) {
                    cnt ++;
                }
                if (cnt == k) {
                    a[p] = 1;
                }
            }
            if (i > n) {
                i = (k - (n - i)) % (n + 1);
            }
            a[i] = 1;
            flag = 1;
        } else {
            i += k % (n + 1);
            if (k == 0) k += 1;
            if (i > n) {
                i = (k - (n - i)) % (n + 1);
            }
            a[i] = 1;
        }
        //printf("%d\n", i);
        n -= 1;
        if (n == 1) break;
    }
    for (int i = 1; i <= m; i++) {
        if (a[i] == 0) {
            cout << i << endl;
            break;
        }
        //cout << a[i] << endl;
    }
    return 0;
}
