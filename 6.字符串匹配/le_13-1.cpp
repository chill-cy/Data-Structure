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


char Rom_ch[10] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0'};
int Rom_num[10] = {1, 5, 10, 50, 100, 500, 1000, 0};

int get_ind(char c) {
    for (int i = 0; i <= 7; i++) {
        if (c == Rom_ch[i]) {
            return i;
        }
    }
}

int romanToInt(char * s){
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        int ind1 = get_ind(s[i]);
        int ind2 = get_ind(s[i + 1]);
        if (Rom_num[ind1] < Rom_num[ind2]) {
            sum -= Rom_num[ind1];
        } else {
            sum += Rom_num[ind1];
        }
    }
    return sum;
}

int main() {
    char str[1000];
    cin >> str;
    
    cout << romanToInt(str) << endl;
    return 0;
}
