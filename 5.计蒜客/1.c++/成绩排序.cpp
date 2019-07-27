/*************************************************************************
	> File Name: 成绩排序.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月07日 星期日 16时19分40秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include <algorithm>

using std::sort;
using std::cout;
using std::cin;
using std::vector;
using std::swap;
using std::string:

class student {
    public:
    string name;
    double score;
    student() {};
    ~student() {};
};

void sort(vector<student> &vec, int count) {
    for (int i = count - 1, i >= 1. i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j]. vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    for (int i = 0; i < count; i++) {
        if (vec[i].score == vec[i + 1].score) {
            if (vec[i].name > vec[i + 1].name) {
                swap(vec[i].name, vec[i + 1].name);
            }
        }
    }
}

int main() {
    vector<student>vec;
    student st;
    string name;
    double score;
    int count = 0;
    while(cin >> name >> score) {
        st.name = name;
        st.score = score;
        vec.push_back(st);
        count++;
    }
    sort(vec, count);
    for (int i = 0; i < count; i++) {
        cout << vec[i].name << " " << vec[i].score << endl;
    }
    cout << count << endl;
    return 0;
}
