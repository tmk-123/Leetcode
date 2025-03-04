#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        if (s.length() == 1) return 1;

        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (!st.empty()) {
                char c = st.top();
                if ((c == 'A' && s[i] == 'B') || (c == 'C' && s[i] == 'D')) st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }

        return st.size();
    }
};