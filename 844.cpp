#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '#') {
                if (!st.empty()) st.pop(); 
            }
            else st.push(c);
        }

        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return convert(s) == convert(t);
    }
};