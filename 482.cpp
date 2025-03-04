#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (res.size() % (k + 1) == k) res += '-'; // tính cả dấu - là k + 1
                res += toupper(s[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};  