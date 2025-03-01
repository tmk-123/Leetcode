#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != s[i + 1] && m[s[i]] % (s[i] - '0') == 0 && m[s[i + 1]] % (s[i + 1] - '0') == 0) return s.substr(i, 2); 
        }
        return "";
    }
};