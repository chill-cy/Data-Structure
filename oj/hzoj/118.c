/*************************************************************************
	> File Name: 118.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月26日 星期三 10时42分25秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;
    year = year - year / 12 * 12;
    char SX[13][10] = {"monkey", "rooster", "dog", "pig", "rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep"};
    
    cout << SX[year] << endl;
    return 0;
}
