/*************************************************************************
	> File Name: d.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月26日 星期四 19时45分39秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
    // To output TrendMicroSoftUSCN
    string strArr1[] = {"Trend", "Micro", "soft"};
    string *pStrArr1 = new string[2];
    pStrArr1[0] = "US";
    pStrArr1[1] = "CN";
    for (int i = 0; i < sizeof(strArr1) / sizeof(string); i++) {
        cout << sizeof(strArr1) << endl;
        cout << sizeof(string) << endl;
        cout << strArr1[i] << endl;
    }
    new string2[2] = {0};
    int len = sizeof(string2);
    cout << endl;
    for (int j = 0; j <= sizeof(pStrArr1) / sizeof(string); j++) {
        cout << sizeof(*pStrArr1) << endl;
        cout << sizeof(string) << endl;
        cout << pStrArr1[j] << endl;
    }
    return 0; 
}
