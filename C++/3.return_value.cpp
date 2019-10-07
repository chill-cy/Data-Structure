/*************************************************************************
	> File Name: 3.return_value.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月07日 星期一 20时25分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << "constructor" << endl;
    }
    A(const A &obj) {
        cout << "copy constructor" << endl;
    }
    //重载赋值运算符
    A &operator=(const A &obj) {
        cout << "operator = " << endl;
        return *this;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};
//这种情况下返回值也是属于值传递，所以temp和中间的匿名变量之间产生了一次拷贝操作，temp把自己的值拷贝给那个匿名变量，然后匿名变量作为a的参数，拷贝给a变量，
A func() {
    A temp;
    cout << &temp << endl;
    return temp;
}

int main() {
    //当a接到了func的值以后，func函数就已经执行完了，所以说明temp在调用a函数的拷贝构造函数之前temp函数早就没了，所以a所接到的值不是temp，而是一个匿名变量
    //每一个对象只有一次构造方法，它的所有构造函数中只有一个能被执行，且只执行一次
    //A b;
    A a = func();
    cout << &a << endl;
    //A a(func(b));
    //a调用了默认构造函数，所以＝不会在调用构造函数，＝仅仅是赋值运算符
    //对象定义阶段调的一定是构造函数，
    //拷贝构造的方法含义和赋值运mZ符在通常情况下是一致的
    //A a, b;
    //a = func(b);
    return 0;
}
