/*************************************************************************
	> File Name: 矩阵螺旋输出.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年05月03日 星期五 21时02分19秒
 ************************************************************************/


#include <iostream>

using namespace std;

 
int main() {
    int matrix[100][100];
    int m, n;
    int i, j;
    cin >> m >> n;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    // 定义方向数组
    int direct[4][2] = {
        {0, 1}, {1, 0},
        {0, -1}, {-1, 0}
    };
    // (x, y) 代表坐标，k 代表方向，l 代表第几圈
    int x, y, k, l;
    x = y = k = l = 0;
    while (1) {
        if (x != 0 || y != 0) cout << " ";
        cout << matrix[x][y];        //除第一个元素外其他元素先输出空格在输出元素值
        if (direct[k][0] != 0) {          //判断水平方向输出元素是否越界
            if (x + direct[k][0] >= m - l || x + direct[k][0] <= l) {   //如果到达水平边界    
                ++k;                          //转到下一个方向
                if (k == 4) {                 //如果循环到第四个方向，转回第一个方向
                    k = 0;                       //并且圈数l增加1
                    ++l;
                }
            }
        } else {                             //判断竖直方向是否到达边界
            if (y + direct[k][1] >= n - l || y + direct[k][1] < l) {
                ++k;                         //到达边界则转下一个方向
            }
        }
        x += direct[k][0];                  //x沿k方向走一步(此句和下一句每次循环实际上只执行其中一个)
        y += direct[k][1];                  //y沿k方向走一步
        if (direct[k][0] != 0 && (x >= m - l || x <= l)) break;   //k方向x坐标是否越界
        if (direct[k][1] != 0 && (y >= n - l || y < l)) break;     //k方向y坐标是否越界
    }
    cout << endl;
    return 0;
}
