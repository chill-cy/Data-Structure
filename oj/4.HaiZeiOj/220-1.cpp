/*************************************************************************
	> File Name: 220-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月05日 星期五 15时20分29秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

struct student {
    string name;
    int score[5], sum;
};
struct student st[105];
bool cmp1(student a, student b) {
    if (a.score[0] == b.score[0]) return a.name < b.name;
    return a.score[0] > b.score[0];
}

bool cmp2(student a, student b) {
    if (a.score[1] == b.score[1]) return a.name < b.name;
    return a.score[1] > b.score[1];
}

bool cmp3(student a, student b) {
    if (a.score[2] == b.score[2]) return a.name < b.name;
    return a.score[2] > b.score[2];
}

bool cmp4(student a, student b) {
    if (a.score[3] == b.score[3]) return a.name < b.name;
    return a.score[3] > b.score[3];
}

bool cmp5(student a, student b) {
    if (a.sum == b.sum) return a.name < b.name;
    return a.sum > b.sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st[i].name;
        for (int j = 0; j < 4; j++) {
            cin >> st[i].score[j];
            st[i].sum += st[i].score[j];
        }
    }
    sort(st, st + n, cmp1);
    for (int i = 0; i < 4; i++) {
        if (i) cout << " ";
        cout << st[i].name;
    }
    cout << endl;
    sort(st, st + n, cmp2);
    for (int i = 0; i < 4; i++) {
        if (i) cout << " ";
        cout << st[i].name;
    }
    cout << endl;
    sort(st, st + n, cmp3);
    for (int i = 0; i < 4; i++) {
        if (i) cout << " ";
        cout << st[i].name;
    }
    cout << endl;
    sort(st, st + n, cmp4);
    for (int i = 0; i < 4; i++) {
        if (i) cout << " ";
        cout << st[i].name;
    }
    cout << endl;
    sort(st, st + n, cmp5);
    for (int i = 0; i < 4; i++) {
        if (i) cout << " ";
        cout << st[i].name;
    }
    cout << endl;
    return 0;
}
