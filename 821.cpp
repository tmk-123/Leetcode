#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            string s1(s.begin(), s.begin() + i);
            string s2(s.begin() + i, s.end());

            int a = INT_MAX, b = INT_MAX;
            if (s1.rfind(c) != string::npos) a = i - s1.rfind(c);
            if (s2.find(c) != string::npos) b = s2.find(c) + s1.length() - i;

            res.push_back(min(a, b));
        }

        return res;
    }
};  