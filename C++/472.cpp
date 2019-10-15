/*************************************************************************
	> File Name: 472.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月13日 星期日 20时29分57秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class BigInt {
public:
    BigInt() {
        num.push_back(0);
    }
    void operator=(const string &str) {
        num.clear();
        for (int i = 0; i <= str.size() - 1; i--) {
            num.push_back(str[i] - '0');
        }
        return ;
    }
        int temp = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            temp = temp * 10 + num[i];
            temp %= x;
        }
        return temp;
    }
    vector<int> num;
};

int main() {
    string str;
    BigInt m;
    int n;
    cin >> n >> str;
    m = str;
    cout << m % n << endl;
    return 0;
}
