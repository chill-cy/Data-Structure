/*************************************************************************
	> File Name: 151.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 11时02分52秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char xm[3];
    char li[3];
    memset(xm, 0, sizeof(xm));
    memset(li, 0, sizeof(li));
    cin >> xm[0] >> xm[1];
    cin >> li[0] >> li[1];
    char s[3][10] = {"MING", "LIHUA", "TIE"};
    if ((xm[0] == 'Y' && li[0] == 'H') || (xm[0] == 'H' && li[0] == 'O') || (xm[0] == 'O' && li[0] == 'Y')) {
        if ((xm[0] == li[1]) || (xm[0] == 'Y' && li[1] == 'H') || (xm[0] == 'H' && li[1] == 'O') || (xm[0] == 'O' && li[1] == 'Y')) {
            cout << s[0];
        } else if ((xm[0] == 'H' && li[1] == 'Y') || (xm[0] == 'O' && li[1] == 'H') || (xm[0] == 'Y' && li[1] == 'O')) {   
            if ((xm[1] == 'Y' && li[1] == 'H') || (xm[1] == 'H' && li[1] == 'O') || (xm[1] == 'O' && li[1] == 'Y')) {
                cout << s[0];
            } else if ((xm[1] == li[1]) || (xm[1] == 'H' && li[1] == 'Y') || (xm[1] == 'O' && li[1] == 'H') || (xm[1] == 'Y' && li[1] == 'O')) {   
                cout << s[1];
            }
        }
    } else if (xm[0] == li[0]) {
        if ((xm[1] == 'Y' && li[1] == 'H') || (xm[1] == 'H' && li[1] == 'O') || (xm[1] == 'O' && li[1] == 'Y')) {
            cout << s[0];
        } else if ((xm[1] == 'H' && li[1] == 'Y') || (xm[1] == 'O' && li[1] == 'H') || (xm[1] == 'Y' && li[1] == 'O')) {   
            cout << s[1];
        } else if (xm[1] == li[1]) {
            cout << s[2];
        }
    } else {
        if ((xm[1] == li[1]) || (xm[1] == 'H' && li[0] == 'Y') || (xm[1] == 'O' && li[0] == 'H') || (xm[1] == 'Y' && li[0] == 'O')) {   
            cout << s[1];
        } else if ((xm[1] == 'Y' && li[0] == 'H') || (xm[1] == 'H' && li[0] == 'O') || (xm[1] == 'O' && li[0] == 'Y')) {
            if ((xm[1] == li[1]) || (xm[1] == 'H' && li[1] == 'Y') || (xm[1] == 'O' && li[1] == 'H') || (xm[1] == 'Y' && li[1] == 'O')) {   
                cout << s[0];
            } else if ((xm[1] == 'H' && li[1] == 'Y') || (xm[1] == 'O' && li[1] == 'H') || (xm[1] == 'Y' && li[1] == 'O')) {   
                cout << s[1];
            }
        }
    }
    cout << endl;
    return 0;
}
