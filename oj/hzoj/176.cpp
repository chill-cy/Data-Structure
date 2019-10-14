/*************************************************************************
	> File Name: 176.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 12时14分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string str, str1;
    getline(cin, str);
    getline(cin, str1);
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        ans = 0;
        for (int k = i, j = 0; k < i + str1.size(); k++, j++) {
            if (str[k] == str1[j]) {
                ans++;          
            } //else {
               // break;
            //}
        } 
        if (ans == str1.size()) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
