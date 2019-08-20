/*************************************************************************
	> File Name: 165.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月20日 星期二 22时36分54秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int compareVersion(char * version1, char * version2){
    int s_len = strlen(version1);
    int t_len = strlen(version2);
    int max = 0;
    if (s_len < t_len) max = t_len;
    else max = s_len;
    int i = 0, j = 0;
    for (int k = 0; k < max; k++) {
        if (version1[i] == '.' || version2[i] == '.') {
            while (version1[i] == '0') {
                i++;
            }
            while (version2[j] == '0') {
                j++;
            }
        }
        if (version1[i] == version1[j]) {
            i++, j++;
        }
        if (version1[i] > version2[j]) return 1;
        else if (version2[i] < version1[j]) return -1;
        if (version1[i] == '\0' || version2[j] == '\0') return 0;
    }
    return 0;
}


int main() {
    char s[10], t[10];
    cin >> s >> t;
    cout << compareVersion(s, t);
}
