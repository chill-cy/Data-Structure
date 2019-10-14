/*************************************************************************
	> File Name: 151-1.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月30日 星期日 11时01分12秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int check (char a, char b) {
    if (a == b) return 0;
    if (a == 'Y' && b == 'H' || a == 'O' && b == 'Y' || a == 'H' && b == 'O') return 1;
    else return 2;
}

int main() {
    char ml, mr, ll, lr;
    cin >> ml >> mr >> ll >> lr;
    if (check(ml, ll) == 1) {
        if (check(ml, lr) != 2) {
            cout << "MING" << endl;
            return 0;
        } else if (check(ml, lr) == 2) {
            if (check(mr, lr) == 1) {
                cout << "MING" << endl;
                return 0;
            } else if (check(mr, lr) != 1){
                cout << "LIHUA" << endl;
                return 0;
            }
        }
    }
    if (check(ml, ll) == 0) {
        if (check(mr, lr) == 1) {
            cout << "MING" << endl;
            return 0;
        }
        if (check(mr, lr) == 2) {
            cout << "LIHUA" << endl;
            return 0;
        }
        if (check(mr, lr) == 0) {
            cout << "TIE" << endl;
            return 0;
        }
    }
    if (check(ml, ll) == 2) {
        if (check(mr, ll) != 1) {
            cout << "LIHUA" << endl;
            return 0;
        }
        if (check(mr, ll) == 1) {
            if (check(mr, lr) != 2) {
                cout << "MING" << endl;
                return 0;
            } else if (check(mr, lr) == 2){
                cout << "LIHUA" << endl;
                return 0;
            }
        }
    }

    return 0;
}
