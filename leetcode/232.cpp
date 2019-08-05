/*************************************************************************
	> File Name: 232.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月05日 星期一 23时59分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
class MyQueue {

    private Stack<Integer> in = new Stack<>();
    private Stack<Integer> out = new Stack<>();

    public void push(int x) {
        in.push(x);
    }

    public int pop() {
        in2out();
        return out.pop();
    }

    public int peek() {
        in2out();
        return out.peek();
    }

    private void in2out() {
        if (out.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.pop());
            }
        }
    }

    public boolean empty() {
        return in.isEmpty() && out.isEmpty();
    }
}
