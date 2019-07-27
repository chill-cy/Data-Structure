/*************************************************************************
	> File Name: test1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月19日 星期五 22时34分31秒
 ************************************************************************/

#include<iostream>
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
        pos = rand() % (top + 1);
        if (pos < top) {
            if (arr1[s[pos + 1]] - arr1[s[pos]] == 1) add(arr1, s[pos])
        }
    }
}
