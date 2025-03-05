#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            res += s[(i + k) % s.length()];
            if (res.size() == s.size()) return res;
        }
        return "";
    }
};