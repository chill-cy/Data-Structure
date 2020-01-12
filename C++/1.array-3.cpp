/*************************************************************************
	> File Name: 1.array-3.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2020年01月04日 星期六 19时02分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T>
class Array {
    public:
    Array() {
        this->__size = 10;
        this->__cnt = 0;
        this->data = new T[this->__size];
    }
    Array(int n) {
        this->__size = 2 * n;
        this->__cnt = n;
        this->data = new T[this->__size];
    }

    void push_back(const T & a) {
        this->data[(this->__cnt)++] = a;
    }

    T & operator[](int index) {
        return this->data[index];
    }

    int size() {
        return this->__cnt;
    }
    
    private:
    T *data;
    int __cnt;
    int __size;
};

int main() {
    Array <int>arr;
    cout << arr.size() << endl;
    arr.push_back(123);
    cout << arr.size() << endl;
    cout << arr[0] << endl;
    Array <int> arr2(10);
    cout << arr2.size() << endl;

    Array <char> arr3;
    arr3.push_back('k');
    cout << arr3[0] << endl;
    arr3.push_back('t');
    cout << arr3[1] << endl;
    cout << arr3.size() << endl;
    return 0;
}
