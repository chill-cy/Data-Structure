/*************************************************************************
	> File Name: lc_36.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月20日 星期二 09时56分34秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int flag[10] = {0};

bool isValidSudoku(char** board){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] < '0' || board[i][j] > '9') continue;
            for (int k = 1; k <= 9; k++) {
                if (board[i][j] - '0' == k) flag[k] += 1;
                //cout << k << endl;
                if (flag[k] >= 2) return false;
            }
        }
        memset(flag, 0, sizeof(flag));
    }
    for (int j = 0; j < 9; j++) {
        for (int  i = 0; i < 9; i++) {
            if (board[i][j] < '0' || board[i][j] > '9') continue;
            for (int k = 1; k <= 9; k++) {
                if (board[i][j] - '0' == k) flag[k] += 1;
                if (flag[k] >= 2) return false;
            }
        }
            memset(flag, 0, sizeof(flag));
    }
    int index[9][2] = {
        0, 0, 0, 3, 0, 6,
        3, 0, 3, 3, 3, 6, 
        6, 0, 6, 3, 6, 6,
    };
    for (int k = 0; k < 9; k++) {
        int x = index[k][0];
        int y = index[k][1];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
            if (board[i][j] < '0' || board[i][j] > '9') continue;
                for (int m = 1; m <= 9; m++) {
                    if (board[x + i][y + j] -'0' == m) flag[m] += 1;
                    if (flag[k] >= 2) return false;
                }   
            }
        }
        memset(flag, 0, sizeof(flag));
    }
    return true;
}

int main() {
    char *board[10];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i] = (char *)malloc(sizeof(char) * 10);
            cin >> board[i][j];
        }
    }
    int boardSize = 9; 
    int *boardColSize;
    bool flag = isValidSudoku(board);
    cout << flag << endl;
    return 0;
}
