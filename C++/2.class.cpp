/*************************************************************************
	> File Name: 2.class.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月07日 星期一 15时14分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
//所有的成员属性基本都要封装成私有的，不能让用户直接操作成员属性，
//如果用户想操作可以为其提供get或set方法
class Point {
public:
    //统计内存中有多少个point类型的对象
    //当我们定义了有参的构造函数的时候，默认构造函数就会被删除了
    //对于成员属性的初始化，还可以使用初始化列表
    //Point()构造函数，_x(0), _y(0)初始化列表，{}构造逻辑
    //先执行初始化列表，再执行构造逻辑，
    //当执行构造逻辑时，当前这个对象已经构造完了，在构造逻辑中可以随便的使用当前对象内部的任何一个方法
    Point() : _x(0), _y(0), _cnt(0) {
        //Point:: c++命名空间的机制，类是一种特殊的命名空间，
        //也相当于调用了类属性，可以用对象的指针去调用类属性this->total;
        //不同对象调用到的total是一样的，因为他是静态属性
        Point::total += 1;
        cout << "Point constructor : " << this << endl;
    }

    //委托构造，当我在执行这个构造函数的时候，先去执行后面的构造函数，然后再执行大括号中的构造逻辑
    Point(int x, int y) : Point() {
        this->_x = x;
        this->_y = y;
        cout << "Point constructor with parameters : " << this << endl;
    }
    //拷贝构造函数,因为在这个方法内部不打算改b的值所以要传一个const类型的变量，这也是为了减少bug.而不是为了实现功能
    //如果发生拷贝行为，而采用传值会将p1拷贝给b,而b是Point类型的，又去调b的拷贝构造函数,又去调b的拷贝构造函数的参数的拷贝构造函数，会发生递归，无限展开，所以拷贝构造函数一定要传引用，可是不写const可以，但是加const可以传入常量值也可以传非常量的值
    Point(const Point &b) : Point(){
        cout << "Point copy constructor : " << this << endl;
        this->_x = b._x;
        this->_y = b._y;
        this->_cnt = b._cnt;
    }
    //Point(int x, int y) {
    //    this->_x = x;
    //    this->_y = y;
    //}
    //this存储当前对象的地址，可以认为this是一个特殊的关键字，准确来说他是C++成员属性内部的一个特殊的指针变量
    //本质上getx,getY是const类型的方法，因为他们方法内部只进行值的读取，不进行值的修改
    //c++默认将当前方法是常量方法，当调用此方法时会自动的将当前对象内部的所有属性全都提升成为const,当这个方法执行完后，再将他们恢复
    int getX() const {
        this->_cnt += 1;
        return this->_x; 
    }
    int getY() const {return this->_y; }
    static int getTotal() {return Point::total; }
    ~Point() {
        this->total -= 1;
        cout << "Point destructor" << endl;
    }
private:
    int _x, _y;
    //在类内部加一个cnt变量，代表当前点的x的值被访问了多少次，
    //可变可不变，当成员属性声明成为mutable时当他在const类型的方法内部，可以把他当成const类型的属性，也可以把他当成非const类型的属性，
    mutable int _cnt;
    //统计点的数量，不是某个对象的行为，他是这个类的行为,所以所有类的对象应该共用一个属性，而这个属性应该是int类型的值，只要声明了一个对象就一定会调用他的构造函数
    //声明，相当于在程序中有一个静态变量，他是point命名空间的静态变量，这是声明，
    static int total;
};
//初始化point命名空间中的变量tatal,将它默认值赋值为０，
int Point::total = 0;
//会将p1拷贝给b,但是如果将b改为引用不会调用拷贝构造函数，地址会和p一样，引用相当于相关对象的别名，它不相当于是一个独立的对象，传进去的是p1,而b是p1的引用所以b是p1的那个对象所以b和p1输出的地址应该是一样的，所以引用是没有发生拷贝行为的
void func(Point &b) {
    cout << "b : " << (&b) << endl;
    return ;
}
//cout输出自定义的类型，重载左移运算符
ostream& operator<<(ostream &out, const Point &p) {
    out << "(" << p.getX() << ", " << p.getY() << ")";
    return out;
}

void func2() {
    Point a, b, c;
}

//当不进行显示的初始化时局部变量相关的值它是随机的
int main() {
    //如果当前拷贝构造函数不加const,当前的p是常量，可我们只有非常量的拷贝构造函数，
    //常量不能绑定在非常量的引用上，会发生逻辑上的冲突，所以c++规定非常量的引用不能绑定在常量的值上，
    //非常量的值可以绑定在常量的引用上，因为你允许我改但是我可以不改
    const Point p(4, 5);
    //调用的是无参构造函数，如果没有显示的无参构造函数，并且定义了有参构造函数，程序会报错,因为无参的构造函数被删除了它就找不到匹配的构造函数了
    //正常的函数传参是会发生一次拷贝操作，但是引用不会发生拷贝行为，指向的对象并没有变
    Point p1(p), p2(p1);
   // cout << p1.getX() << " " << p1.getY() << endl;
    func(p1);
    //cout所对应的类重载了左移运算符，所以cout是一个对象，所以我们可以实现cout,因为它只是一个普通的对象
    //要重载左移运算符，这个左移运算符的返回值是cout
    //cout的类是ostream
    //等价于cout.operator<<(p1)
    func2();
    cout << p1 << " " << p2 << endl;
    cout << Point::getTotal() << endl;
    return 0;
}
