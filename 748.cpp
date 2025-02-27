#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<int, int> m;
        for (char c : licensePlate) {
            if (!isalpha(c)) continue;
            c = tolower(c);
            m[c]++;
        }
        
        string res;
        int minLen = INT_MAX;
        for (string s : words) {
            unordered_map<int, int> m1 = m;
            for (char c : s) {
                if (m1.find(c) != m1.end()) {
                    m1[c]--;
                    if (m1[c] == 0) m1.erase(c);
                }
            }

            if (m1.empty() && s.length() < minLen) {
                res = s;
                minLen = s.length();
            }
        }
        
        return res;
    }
};