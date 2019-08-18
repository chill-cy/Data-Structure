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


char Rom_ch[10] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int Rom_num[10] = {1, 5, 10, 50, 100, 500, 1000};

int romanToInt(char * s){
    int len = strlen(s);
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        for (int k = 0; k < 7; k++) {
            if (s[i + 1] == Rom_ch[k]) {
                ans = Rom_num[k];
                break;
            }
        }
        for (int j = 0; j < 7; j++) {
            if (s[i] == Rom_ch[j]) {
                if (Rom_num[j] < ans) {
                    sum -= Rom_num[j];
                } else {
                    sum += Rom_num[j];
                }
            } 
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
