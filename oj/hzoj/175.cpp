/*************************************************************************
	> File Name: 175.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 12时05分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int num[5] = {0};
    int n;
    cin >> n;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> score;
        if (score >= 90 && score <= 100) {
            num[0]++;
        } else if (score >= 80) {
            num[1]++;
        } else if (score >= 60) {
            num[2]++;
        } else {
            num[3]++;
        }
    }      
    string str[4] = {"You", "Liang", "Zhong", "Cha"};
    for (int i = 0; i < 4; i++) {
        cout << str[i] << " " << num[i] << endl;
    }
    return 0;
}
