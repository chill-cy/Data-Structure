/*************************************************************************
	> File Name: test1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 22时32分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <time.h>
#include <stack>
using namespace std;
int arr1[5000];
int arr2[5000];
int s[5000];
int pos, top = -1;

void add(int *arr, int n, int ind, int val) {
    for (int i = ind; i < n; i++) {
        arr[i] += val;
    }
    return ;
}

int main() {
    int n;
    srand(time(0));
    cin >> n;
    s[++top] = 0;
    int p = rand() % n + 1;
    for (int i = 1; i <= n; i++) {
        //s记录数组下标，pos随机插入栈中的位置
        pos = rand() % (top + 1);
        if (pos < top) {
            if (arr1[s[pos + 1]] - arr1[s[pos]] == 1) add(arr1, s[pos] + 1, i, rand() % 10 + 5);
            if (arr2[s[pos + 1]] - arr2[s[pos]] == 1) add(arr2, s[pos] + 1, i, rand() % 10 + 5);
        }
        int val1 = rand() % (pos == top ? 20 : arr1[s[pos + 1]] - arr1[s[pos]] - 1) + 1;  
        int val2 = rand() % (pos == top ? 20 : arr2[s[pos + 1]] - arr2[s[pos]] - 1) + 1;  
        arr1[i] = arr1[s[pos]] + val1;
        arr2[i] = arr2[s[pos]] + val2;
        while (arr1[s[pos]] > arr1[i]) --top;
        s[++top] = i;
    }
    for (int i = p+1; i<=n; i++) {
        arr1[i] = rand() % 1000;
        arr1[i] = rand() % 1000;
    }
    for (int i = 1; i <= n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
