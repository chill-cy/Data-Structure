/*************************************************************************
	> File Name: 203.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 16时38分04秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int ans[15][15];
    int range[15];
    int max[15] = {0};
    int sum = 0;
    int high[300];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ans[i][j];
            sum += ans[i][j];
            high[k] = ans[i][j];
            k++;    
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (max[j] < ans[i][j]) {
                max[j] = ans[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << max[i] << endl;
    }
    sort(high, high + k, greater<int>());
    for (int i = 0; i < k; i++) {
        if (i) cout << " ";
        cout << high[i];
    }
    cout << endl;
    //int arv = (sum * 10) / ((m * n)*10);
    //if (arv % 10 > 4) cout << arv / 10 + 1 << endl;
    int val = sum % (m*n);
    if (val >= ((m*n) / 2)) {
        sum /= (m*n);
        sum += 1;
    }else{
        sum /= (n*m);
    }
    cout << sum << endl;
    //else cout << arv / 10 << endl;
    int i, num = 0;
    for (i = 0; i < n * m; i++) {
        if (high[i] >= sum) {
            num++;
        }
    }
    cout << num << endl;
    return 0;
}
