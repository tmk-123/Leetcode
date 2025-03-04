#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string finalString(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'i') {
                reverse(s.begin(), s.begin() + i);
            }
        }

        string res;
        for (char c : s) {
            if (c != 'i') res += c;
        }
        return res;
    }
};