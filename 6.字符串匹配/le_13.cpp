/*************************************************************************
	> File Name: le_13.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月18日 星期日 22时10分16秒
 ************************************************************************/

#include<iostream>
#include <string.h>
#include <map>
using namespace std;

map<char, int> m;

char Rom_ch[10] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int Rom_num[10] = {1, 5, 10, 50, 100, 500, 1000};

int romanToInt(char * s){
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (m[s[i]] < m[s[i + 1]]) {
            sum -= m[s[i]];
        } else {
            sum += m[s[i]];
        }
    }
    return sum;
}

int main() {
    char str[1000];
    cin >> str;
    for (int i = 0; i < 7; i++) {
        m[Rom_ch[i]] = Rom_num[i];
    }
    cout << romanToInt(str) << endl;
    return 0;
}
