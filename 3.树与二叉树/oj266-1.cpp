/*************************************************************************
	> File Name: oj266-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月02日 星期三 13时21分57秒
 ************************************************************************/

#include<iostream>
#include <stack>
using namespace std;
#define MAX_N 1000
stack<char> mystack;

int main() {
    char str[MAX_N + 5];
    cin >> str;
    int ans = 0;
    for (int i = 0; str[i]; i++) {
        switch(str[i]) {
            case '(': {
                mystack.push(str[i]);
            } break;
            case ')': {
                char val1 = mystack.top();
                mystack.pop(); 
                char val2 = mystack.top();
                mystack.pop(); 
                char val3 = mystack.top();
                mystack.pop(); 
                switch(val2) {
                    case '*': ans += val1 * val3; break;
                    case '/': ans += val1 / val3; break;
                    case '+': ans += val1 + val3; break;
                    case '-': ans += val1 - val3; break;
                }
            }
            default: mystack.push(str[i]); break;
        }
    }
    cout << ans << endl;
    return 0;
}
