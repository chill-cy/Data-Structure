/*************************************************************************
	> File Name: str.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月05日 星期六 17时54分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    char str[10000];
    scanf("%[^\n]s", str);
    char str2[10000];
    int k = 0;
    for (int i = 0, j = 0; str[i]; i++) {
        if (str[i] != ' ' || str[i] != '\n') k++;
        else {
            cout << '1' << endl;
            int m = i - k;
            while (k) {
                str2[j++] = str[m++];
                k--;
                cout << str[m] << endl;
            }
            cout << str2 << endl;
        }
    }
    cout << str2;
    return 0;
}
