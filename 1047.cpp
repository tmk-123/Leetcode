#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            }  
            else st.push(s[i]);
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};