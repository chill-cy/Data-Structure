/*************************************************************************
	> File Name: f.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月28日 星期六 19时57分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

class SC
{
    public:
    SC(int r) {R = &r;};
    int Get() {return *R;};
    private:
    int *R;


};

int main() {
    SC C(10);
    cout << C.Get() << endl;
    return 0;
}
