/*************************************************************************
	> File Name: 2.256-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2020年01月05日 星期日 22时37分42秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Data {
    int a, b;
    bool operator<(Data const & obj) {
        return a * b < obj.a * obj.b;
    }
};

class BigInt {
    public:
    BigInt() {}
    BigInt(const int & x) {
        num.push_back(x);
        process_digit();
    }

    void process_digit() {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] = num[i] % 10;
        }  
    }
    
    void operator*=(int x) {
        for (int i = 0; i < num.size(); i++) num[i] *= x;
        process_digit();
    }
    
    BigInt(vector<int> & ret): num(ret) {}

    BigInt operator/(int x) {
        int i = num.size(), temp = 0;
        //易错:当除数小于被除数时商为0
        while(i && temp * 10 + num[i - 1] < x) temp = temp * 10 + num[i - 1], i--; 
        if (i == 0) return BigInt(0);
        vector<int> ret(i);
        while (i) {
            temp = temp * 10 + num[i - 1];
            ret[i - 1] = temp / x;
            temp = temp % x;
            i--;
        }
        return BigInt(ret);
    } 

    vector <int> num;
};

ostream & operator<<(ostream & out, const BigInt & obj) {
    for (int i = obj.num.size() - 1; i >= 0; i--) {
        cout << obj.num[i];
    }
    return out;
}

vector <Data> arr;

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; i++) cin >> a >> b, arr.push_back({a, b});
    sort(arr.begin() + 1, arr.end());
    BigInt ans, p = arr[0].a;
    for (int i = 1; i <= n; i++) {
        if (i == n) ans = p / arr[i].b;
        p *= arr[i].a;
    }
    cout << ans << endl;
    return 0;
}
