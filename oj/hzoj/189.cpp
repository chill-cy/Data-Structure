/*************************************************************************
	> File Name: 189.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 21时37分30秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000000

int main() {
    long long n, k;
    cin >> n >> k;
    int Ni[MAX_N + 5];
    int Nj[MAX_N + 5];
    for (int i = 1; i <= n; i++) {
        cin >> Ni[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> Nj[i];
    }
    int ind[MAX_N + 5] = {0};
    for (int i = 0; i < k; i++) {
        int a = 1, b = n;
        int mid = (a + b) / 2;
        while(a <= b) {
            int mid = (a + b) / 2;
            if (Ni[mid] == Nj[i]) {
                ind[i] = mid;
                cout << mid << " ";
                break;
            }
            if (Ni[mid] > Nj[i]) {
                b = mid - 1;
            } 
            if (Ni[mid] < Nj[i]){
                a = mid + 1;
            }
        }
        if (a > b) ind[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        if (i != 0) cout << " ";
        cout << ind[i];
    }
    cout << endl;
    return 0;
}
