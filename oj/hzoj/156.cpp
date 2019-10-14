/*************************************************************************
	> File Name: 156.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 14时59分50秒
 ************************************************************************/

#include<iostream>
#include <math.h>

using namespace std;

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int is_valid(int x) {
    int a = (int)sqrt(x);
    return a * a == x;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int flag = 0;
    for (int i = a; i <= b; i++) {
        if (is_prime(i) && is_valid(i / 100) && is_valid(i % 100)){
            ans++;
            if (flag) {
                cout << " ";
            }
            flag = 1;
            cout << i;
        }
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}
