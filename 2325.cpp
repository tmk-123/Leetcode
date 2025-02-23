#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        char ch = 'a';
        for (char c : key) {
            if (c != ' ' && m.find(c) == m.end()) {
                m[c] = ch++;
            }
        }

        string res;
        for (char c : message) {
            if (c != ' ') {
                res += m[c];
            }
            else res += c;
        }
        return res;
    }
};