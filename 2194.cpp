#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char s1 = s[0], s2 = s[3];
        char n1 = s[1], n2 = s[4];
        vector<string> res;

        for (char c = s1; c <= s2; c++) {
            string t;
            t += c;
            for (char n = n1; n <= n2; n++) {
                t.push_back(n);
                res.push_back(t);
                t.pop_back();
            }
                
        }
        return res;
    }
};