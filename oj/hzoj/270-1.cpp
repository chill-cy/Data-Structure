/*************************************************************************
	> File Name: 270-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月17日 星期三 23时08分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 300000
long long q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];
//有求和操作结果可能超int的表示范围
int main() {
    long long n, m, ans;
    cin >> n >> m;
    //arr[0],记录前0项和，arr[j]记录前j项和
    for (int i = 1; i <= n; i++) {
        cin >> arr[i], arr[i] += arr[i - 1];
    }
    tail = head = 0;
    q[tail++] = 0;//存储相关元素的下标
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        //将当前元素压入队列之前，保证队尾元素满足单调性，否则出队
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        //记录将当前元素下标，
        q[tail++] = i;
        //判断队首元素是否过期，当前单调队列中最后一个元素是i,他所能维护的第一个元素是i - m + 1, 如果队首元素的坐标如果等于i-m时证明过期了，如果队首元素过期则出队

    }
    cout << ans << endl;
    return 0;
}
