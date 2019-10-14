/*************************************************************************
	> File Name: 270.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月17日 星期三 17时09分49秒
 ************************************************************************/

#include<iostream>

#define MAX_N 300000
#define max(a, b) ((a) > (b)) ? (a) : (b)
using namespace std;
int q[MAX_N + 5];
int arr[MAX_N + 5];
int main()
{
    int head, tail;
    long long n, m, ans;
    cin >> n >> m;
    for(int i =1 ; i <= n; i++){
        cin>>arr[i],arr[i] += arr[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0; // 存储下标
    for(int i = 1;i <= n;i++)
    {
        ans = max(ans,arr[i] - arr[q[head]]);
        //尾部元素违反单调性出队
        while(tail - head && arr[q[tail - 1]] >= arr[i]) {
            tail --;
        }
        q[tail++] = i;
        //判断队首元素是否过期;
        if(q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}
