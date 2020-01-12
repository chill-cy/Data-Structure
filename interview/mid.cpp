/*************************************************************************
	> File Name: mid.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月29日 星期二 11时24分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

void qk(int *s, int val, int l, int r) {
    int x = l, y = r, z = l;
    while (x < y) {

    }
}

int binary_search(int *s, int val, int l, int r) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (s[mid] == val) return mid;
        else if (s[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
}

int main() {
    int n, q, a[100];
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    int mid = binary_search(a, q, 0, n - 1);
    cout << mid;
}
