#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                if (c == "+") st.push(left + right);
                else if (c == "-") st.push(left - right);
                else if (c == "*") st.push(left * right);
                else st.push(left / right);
            }
            else {
                st.push(stoi(c));
            } 
        }   

        return st.top();
    }
};

int main() {
    string s;
    vector<string> v;
    while (cin >> s) {
        v.push_back(s);
    }

    Solution sol;
    cout << sol.evalRPN(v);
}