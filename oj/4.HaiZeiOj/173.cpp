/*************************************************************************
	> File Name: 173.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月03日 星期三 11时40分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int num[5] = {0};
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'z') num[0]++;
        else if (str[i] <= '9' && str[i] >= '0') num[1]++;
        else if (str[i] == ' ') num[2]++;
        else num[3]++;
    }
    for (int i = 0; i < 4; i++) {
        if (i != 0) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return 0;
}
