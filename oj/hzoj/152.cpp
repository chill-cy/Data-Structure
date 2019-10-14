/*************************************************************************
	> File Name: 152.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 11时25分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    char day[8][15] = {"Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday", "Sunday"};
    cin >> n;
    n -= 1;
    n = (n + 3) % 7;
    cout << day[n] << endl;
    return 0;
}
