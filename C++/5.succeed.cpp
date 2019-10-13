/*************************************************************************
	> File Name: 5.succeed.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月13日 星期日 18时24分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define P_ADD(x) cout << #x << " : " << &(x)

class Animal {
public:
    Animal(const char *name) : _name(name) {
        cout << "Animal : " << this << endl;
    }
    const string &name() const {return this->_name; }
    int x, y;
private:
    const char *_name;
};

class Cat : public Animal {
public : 
    Cat() : Animal("hello kitty") {
        cout << "Cat : " << this << endl;
    }
    int z;
};

class Dag : public Animal {
public : 
    Dag() : Animal("Anby") {
        cout << "Dog : " << this << endl;
    }
    int z;
};

class Monkey {
public:
    Monkey() : Animal("Monkey 666") {
        cout << "Monkey 666 : " << this << endl;
    }
    int z;
};

ostream &operator<<(ostream &out, const Cat &a) {
    out << "<class Cat> : ";
    out << a.name();
    return out;
}

ostream &operator<<(ostream &out, const Dog &a) {
    out << "<class Cat> : ";
    out << a.name();
    return out;
}

ostream &operator<<(ostream &out, const Monkey &a) {
    out << "<class Cat> : ";
    out << a.name();
    return out;
}

int main() {
    Cat a;
    cout << a << endl;
    
    return 0;
}
