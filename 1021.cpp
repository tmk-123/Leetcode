#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c; // chừa lại (
            if (c == ')' && opened-- > 1) res += c; // chừa lại )
        }
        return res;
    }
};