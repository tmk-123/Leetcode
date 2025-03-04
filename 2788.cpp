#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (string& s : words) {
            Try(s, separator, res);
        }
        return res;
    }

    void Try(string s, char c, vector<string>& res) {
        if (s == "") return;

        if (s.find(c) != string::npos) {
            int i = s.find(c);
            string s1 = s.substr(0, i);
            string s2 = s.substr(i + 1);
            Try(s1, c, res);
            Try(s2, c, res);
        }
        else res.push_back(s);
    }
};