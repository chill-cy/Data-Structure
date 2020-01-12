/*************************************************************************
	> File Name: 2.256-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2020年01月04日 星期六 21时11分05秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
    int a, b;
    bool operator<(const Data & obj) {
        return a * b < obj.a * obj.b;
    }
};

vector <Data> arr;


int main() {
    
    int n, a, b;
    int k, t;
    cin >> k >> t;
    if (k - t) cout << t << endl;
   /* cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin() + 1, arr.end());
    int p = arr[0].a, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p / arr[i].b > ans) ans = p / arr[i].b;
        p *= arr[i].a;
    }
    cout << ans << endl;
    */return 0;
}
