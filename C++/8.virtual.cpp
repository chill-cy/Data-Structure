/*************************************************************************
	> File Name: 8.virtual.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月30日 星期三 00时21分47秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct Animal {
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
    virtual void test(int x) {
        cout << this << endl;
        cout << x << endl;
        cout << "Class Animal test" << endl;
    }
};

struct Cat : Animal {
    void run() {
        cout<< "I can run like a cat" << endl;
    }
};

struct Dog : Animal {
    void run() {
        cout << "I can run like a dog" << endl;
    }
    void test(int) {
        cout << "Class Dog test" << endl;
    }
};

struct Bat : Animal {
    int age;
};

typedef void (*func_t)();
typedef void (*func_t1)(void *, int);

int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) {
            arr[i] = new Cat;
        } else {
            arr[i] = new Dog;
        }
    }
    arr[8]->run();
    cout << sizeof(Bat) << endl;
    Cat a;
    ((func_t **)(&a))[0][0]();
    ((func_t1 **)(&a))[0][1](&a, 123);
    return 0;
}
