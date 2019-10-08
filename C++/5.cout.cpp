/*************************************************************************
	> File Name: 5.cout.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月08日 星期二 18时35分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

namespace haizei {
    class ostream {
    public:
        ostream &operator<< (int x) {
            printf("%d", x);
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const char &ch) {
            printf("%c", ch);
            return *this;
        }
        ostream &operator<<(const double &a) {
            printf("%g", a);
            return *this;
        }
    };
    char endl = '\n';
    ostream cout;
}

int main() {
    haizei::cout << "hello world" << haizei::endl;
    haizei::cout << 123 << haizei::endl;
    haizei::cout << 123.567 << haizei::endl;
    haizei::cout << 123.56 << haizei::endl;
    haizei::cout << 123. << 123. << haizei::endl;
    std::cout << 123. << 123. << std::endl;
    haizei::cout << 123.78787878 << haizei << endl;
    haizei::cout << 3.78787878 << haizei::endl;
    double a = 378
    return 0;
}
