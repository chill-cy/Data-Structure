/*************************************************************************
	> File Name: 191-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月11日 星期四 22时38分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 8000000

int prime[MAX_N + 5] = {0};
int main() {
    int l, r;
    cin >> l >> r;
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break; 
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    //for (int i = 1; i < 10; i++) {
      //  cout << prime[i] << endl;
    //}
    int min[3] = {0}, max[3] = {0}, k = 0;
    for (int j = 1; j < MAX_N; j++) {
        if (prime[j] >= l && prime[j] <= r && k == 0) {
            min[1] = prime[j];
            k = 1;
            continue;
        }
        if (prime[j] >= l && prime[j] <= r && k == 1) {
            min[2] = prime[j];
            cout << min[1] << "," << min[2] << " are closest, ";
            break;
        }
    }
    int f = 0, ans = 0;
    for (int j = r; j >= 1; j--) {
        if (prime[j] <= r && f == 0 && prime[j] >= l) {
            max[1] = prime[j];
            f = 1;
            continue;
        }
        if (prime[j] <= r && f == 1 && prime[j] >= l) {
            max[2] = prime[j];
            /*
            if (max[1] - max[2] >= ans) {
                ans = max[1] - max[2];
                max[1] = 0;
                max[2] = 0;
                continue;
            }*/
            cout << max[2] << "," << max[1] << " are most distant." << endl;
            break;
        }
    }
    if (!max[1] || !max[2] || !min[1] || !min[2]) {
        cout << "There are no adjacent primes." << endl;
    }
    return 0;
}
