#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() != 2) {
            string t;
            for (int i = 1; i < s.length(); i++) {
                t += string(1, (s[i] + s[i - 1]) % 10 + '0');
            }
            s = t;
        }

        return s[0] == s[1];
    }
};