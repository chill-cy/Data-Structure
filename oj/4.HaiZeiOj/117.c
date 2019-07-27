/*************************************************************************
	> File Name: 117.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 10时00分25秒
 ************************************************************************/

#include <iostream>

using namespace std;
int is_valid(int a) {
    int temp = 0, raw = a; 
    while (a) {
        temp = temp * 10+ a % 10;
        a /= 10;
    }
    return raw == temp;
}

int main() {
    int a;
    cin >> a;
    if (is_valid(a)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}
