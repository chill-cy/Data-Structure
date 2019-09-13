/*************************************************************************
	> File Name: oj233.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月03日 星期二 22时15分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000

int arr[MAX_N + 5];
int A[MAX_N + 5], B[MAX_N + 5];
int main() {
    int n, p, h, m;
    cin >> n >> p >> h >> m;
  
    for (int i = 1; i <= m; i++) {
        cin >> A[i] >> B[i];
        int min;
        if (A[i] > B[i]) swap(A[i], B[i]);
        if (A[i] == p) arr[B[i]] = h;
        if (B[i] == p) arr[A[i]] = h;
        if (A[i] <= A[i - 1] && B[i] >= B[i - 1]) {
            if (arr[A[i]] < arr[B[i]]) min = arr[A[i]];
            else min = arr[B[i]];
            for (int i = A[i] + 1; i < B[i]; i++) {
                arr[i] -= 1;
                if (arr[i] == min) arr[i] -= 1;
            }
        }
    }
    sort(arr, arr + m, cmp1);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
