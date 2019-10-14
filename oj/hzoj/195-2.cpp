/*************************************************************************
	> File Name: 195-2.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月06日 星期六 10时13分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_N 100000

int a[MAX_N + 5];
int b[MAX_N + 5];
int ans[MAX_N + 5];
int half_serach(int l, int r, int val) {
    int mid ;
    while (l <= r){
        mid = (l+r) /2;
        if (a[mid] <= val && a[mid + 1] > val) return mid;
        if (a[mid] <= val && mid == r) return mid;
        if (a[mid] < val) l = mid + 1;
        else if (a[mid] > val) r = mid - 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        ans[j] = half_serach(0, n-1, b[j]);
    }
    for (int i = 0; i < m; i++) {
       if(i >0) cout <<" ";
        cout << a[ans[i]] ;
    }
    cout << endl;
    return 0;
}
