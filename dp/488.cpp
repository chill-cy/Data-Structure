/*************************************************************************
	> File Name: 488.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月23日 星期三 02时41分49秒
 ************************************************************************/


/*
 * 地图上有 nn 个城市，某人想从 11 号城市开始依次经过这些城市，最终到达 nn 号城市。但是他觉得这样太无聊了，所以决定跳过其中的一个城市（但是不能跳过 11 号和 nn 号城市），使得他从 11 号城市开始，到达 nn 号城市所经过的总距离最小。
城市 AA 的坐标为 XA,YAXA,YA，城市 BB 的坐标为 XB,YBXB,YB，则两城距离为 ∣∣XA−AB∣∣+∣∣YA−YB∣∣|XA−AB|+|YA−YB|。
 */
#include<iostream>
#include <cmath>
using namespace std;
#define MAX_N 100000

struct point {
    int x, y;
} point[MAX_N + 5];

int dis(struct point &a, struct point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int dp(int n, int key) {
    if (n == 1) return 0;
    if (n == 2) return dis(point[2], point[1]);
    if (key == 0) return dp(n - 1, 0) + dis(point[n], point[n - 1]);
    else if (key == 1) {
        return min(dp(n - 1, 1) + dis(point[n], point[n - 1]), dp(n - 2, 0) + dis(point[n - 2], point[n]));
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> point[i].x >> point[i].y;
    cout << dp(n, 1) << endl;
    return 0;
}
