#include<bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        stack<int> newSt;
        while (!st.empty()) {
            newSt.push(st.top());
            st.pop();
        }
        st = newSt;
    }
    
    int pop() {
        int top = st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};