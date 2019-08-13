/*************************************************************************
	> File Name: 287.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月12日 星期一 19时11分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef pair<int, int> PII;

set<PII> s;

int main() {
    int n, a, sum = 0;
    cin >> n;
    while (n--) cin >> a, s.insert(PII(a, n));
    while (s.size() != 1) {
        
    }
    return 0;
}
