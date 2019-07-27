/*************************************************************************
	> File Name: 195.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月04日 星期四 01时22分18秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000
int main() {
    int n, m;
    cin >> n >> m;
    long long int a[MAX_N + 5], b[MAX_N + 5]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
   // sort(a, a + n);
    int flag = 0;
    
    for (int i = 0; i < n; i++) {
        //int l = 1, r = b[i];
        if (i != 0) cout << " ";
        if(b[i] < a[0]) {
            cout << a[0];
            continue;
        }
        int k;
        for (k = 0; a[k] < b[i]; k++);
        if (a[k] > b[i]) {
            k--;
            cout << a[k];
        } else if (a[k] == b[i]) {
            cout << a[k];
        }
        /*while (l <= r) {
            int mid = (l + r) / 2;
            if (a[n] == b[i]) {
                cout << a[mid] << " ";
                flag = 1;
                break;
            } 
            if (a[mid] < b[i]) {
                l = mid + 1;
            }
            if (a[mid] > b[i]) {
                r = mid - 1;
            }
            n--;
        }
        if (flag == 0) {
            if (i != 0) cout << " ";
            cout << a[l - 1];
        }*/
    }
    cout << endl;
    return 0;
}
