/*************************************************************************
	> File Name: 191.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 23时43分10秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 8000
int prime[MAX_N + 5] = {0};

int main() {
    int l, r;
    cin >> l >> r;
    long long int a[3] = {0}, b[3] = {0};
    int max = 0, min = MAX_N;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i < prime[0]; i++) {
        cout << prime[i] << endl;
        /*if (prime[i] >= l && prime[i] <= r 
            && prime[i + 1] >= l&& prime[i + 1] <= r) {
            if (max < prime[i + 1] - prime[i]) {
                max = prime[i + 1] - prime[i];
                a[0] = prime[i];
                a[1] = prime[i + 1];
            } 
            if (min > prime[i + 1] - prime[i]) {
                min = prime[i + 1] - prime[i];
                b[0] = prime[i];
                b[1] = prime[i + 1];
            }
        }*/
    }
   /* if (min != MAX_N) {
        cout << a[0] << "," << a[1] << " are closest, ";
    } 
    if (max != 0) {
        cout << b[0] << "," << b[1] << " are most distant.";
    }
    if (min == MAX_N && max == 0) {
        cout << "There are no adjacent primes.";
    }
    cout << endl;*/
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX_N 8000000
int prime[MAX_N + 5] = {0};

int main() {
    int l, r;
    cin >> l >> r;
    for (int i = 2; i <= r; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > r) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int min = MAX_N;
    int max = -9999;
    int a, b, c, d;
    int cnt = 0;
    for (int j = 1; prime[j + 1] <= r && j + 1 <= prime[0]; j++) {
        if (prime[j] < l) continue;
        cnt ++;
        if (prime[j + 1] - prime[j] < min) {
            a = prime[j];
            b = prime[j + 1];
            min = prime[j + 1] - prime[j];
        }
        if (prime[j + 1] - prime[j] > max) {
            c = prime[j];
            d = prime[j + 1];
            max = prime[j + 1] - prime[j];
        }
    }
    if (cnt < 2) {
        cout << "There are no adjacent primes." << endl;
    } else {
        printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
    }
    return 0;
}
