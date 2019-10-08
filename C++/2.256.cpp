/*************************************************************************
	> File Name: 2.256.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月08日 星期二 20时43分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Data {
    int a, b;
    bool operator<(const Data &obj) const {
        return a * b < obj.a & obj.b;
    }
};
vector<Data> arr;

struct BigInt {
    BigInt(int x) {
        num.push_back(x);
        proccess_digit();
    }
    void proccess_digit() {
        for (int i = 0; i < nun.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[]
        }
        return ;
    }
    vector<int> num;

};

int main() {
    int n, a, b, ans;
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin() + 1, arr.end());
    BigInt p = arr[0].a, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p / arr[i].b > ans) ans = p / arr[i].b;
        p *= arr[i].a;
    }
    cout << ans << endl;
    return 0;
}
