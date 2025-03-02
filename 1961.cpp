#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefixString = "";
        int i = 0;
        while (i < words.size()) {
            prefixString += words[i++];
            if (prefixString == s) return true;
            if (prefixString.length() > s.length()) return false;
        }
        return false;
    }
};