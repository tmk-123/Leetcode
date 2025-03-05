#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char& c : s) {
            if (isalpha(c)) st.push(c);
            else {
                if (!st.empty()) st.pop();
            }
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};