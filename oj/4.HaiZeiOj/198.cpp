/*************************************************************************
	> File Name: 198.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 15时18分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
#define MAX_M 1000000007
int keep[MAX_N + 5] = {0, 1, 1};
int f(int n) {
    if (n == 1 || n == 2) return 1;
    if (!keep[n]) {
        keep[n] = f(n - 1) + f(n - 2);
    }
    return keep[n] % MAX_M;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
