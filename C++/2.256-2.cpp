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
    bool operator<(const Data & obj) const {
        return a * b < obj.a * obj.b;
    }
};

vector <Data> arr;

class BigInt {
    public:
    BigInt(int x) {
        number.push_back(x);
        process_bigint();
    }
    void process_bigint() {
        for (int i = 0; i < number.size(); i++) {
            if (number[i] < 10) continue;
            if (number.size() == i + 1) number.push_back(0);
            number[i + 1] += number[i] / 10;
            number[i] %= 10;
        }
        return ;
    }
    void operator*=(int x) {
        for (int i = 0; i < number.size(); i++) number[i] *= x;
        process_bigint();
    }

    BigInt(vector<int> &ret) : number(ret) {}
    
    BigInt operator/(int x) {
        int i = number.size(), temp = 0;
        while (i && temp * 10 + number[i - 1] < x) temp = temp * 10 + number[i - 1], i--;
        if (i == 0) return BigInt(0);
        vector <int> ret(i);
        while (i) {
            i--;
            temp = temp * 10 + number[i];
            ret[i] = temp / x;
            temp %= x;
        }
        return BigInt(ret);
    }

    bool operator>(const BigInt & obj) {
        if (number.size() - obj.number.size()) return number.size() > obj.number.size();
        for (int i = number.size() - 1; i >= 0; i--) {
            if (number[i] == obj.number[i]) continue;
            return number[i] > obj.number[i];
        }
        return false;
    }
    vector <int> number;

};
ostream & operator<<(ostream & out, const BigInt & obj) {
    for (int i = obj.number.size() - 1; i >= 0; i--) {
        out << obj.number[i];
    }
    return out;
}

int main() {
    
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; i++) {
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
