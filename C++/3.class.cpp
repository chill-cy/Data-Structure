/*************************************************************************
	> File Name: 3.class.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月10日 星期四 20时08分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    Point() : _x(0), _y(0) {}
    Point(int x, int y) : _x(x), _y(y) {}
    Point(Point p) {
        _x = 
    }
    int x() { return _x; }
    int y() { return _y; }
private:
    int _x, _y;
};

int main() {
    int p1, p2(2, 3);
    return 0;
}
