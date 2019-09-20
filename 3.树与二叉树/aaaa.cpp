/*************************************************************************
	> File Name: aaaa.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月20日 星期五 20时57分54秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200000
long long a[MAX_N + 5], b[MAX_N + 5], c[MAX_N + 5][MAX_N + 5];

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long j = 0; j < n; j++) {
        cin >> b[j];
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            c[i][j] = a[i] * a[j];
        }
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n - 1; j++) {
            c[i][j] ^= c[i][j + 1];
        }
    }
    cout << c[n - 1][n - 2] << endl;
    return 0;
}
