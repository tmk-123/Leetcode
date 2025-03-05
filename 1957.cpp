#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;

        string res = s.substr(0, 2);  
        for (int i = 2; i < s.length(); i++) {
            if (s[i] != s[i - 1] || s[i] != s[i - 2]) res += s[i];
        }
        return res;
    }
};