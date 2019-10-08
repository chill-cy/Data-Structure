/*************************************************************************
	> File Name: 3.succeed.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月08日 星期二 11时49分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    //拷贝和赋值这两个操作在有继承的程序中如何进行使用
    Animal(const string &name) : _name(name) {
        cout << "Animal Constructor" << endl;
    }
    Animal(const string &name, int x) : _name(name), _x(x) {}
    //子类只能够继承public和protected中的，代表它只能访问到这两个地方
    string name() { return this->_name; }
    ~Animal() {
        cout << "Animal Destructor" << endl;
    }

    private :
    string _name;
};

class Cat : public Animal {
public : 
    Cat() : Animal("cat-1") {
        cout << "Cat Constructor" << endl;
    }
    Cat(string name, int x, int y) : Animal(name, x), _y(y) {}
    int y() {return this->_y; }
    ~Cat() {
        cout << "Cat Destructor" << endl;
    }
private:
    int _y;
};

ostream &operator<<(ostream &out, Cat &a) {
    out << "<Class Cat>";
    out << a.name();
    return out;
}
//当主函数结束了以后，因为局部变量要被销毁，又因为这个局部变量是一个对象，所以系统去调用这个局部变量的析构函数
int main() {
    Cat c1("hello kitty", 34, 54);
    Cat c2(c1);
    cout << c << endl;
    return 0;
}
