#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        string res;
        stringstream ss(sentence);
        string s, t = "ueoaiUEOAI";
        int cnt = 1;
        while (ss >> s) {
            if (t.find(s[0]) == string::npos) {
                res += string(s.begin() + 1, s.end()) + s[0];
            }
            else res += s;

            res += "ma" + string(cnt, 'a') + " ";
            cnt++;
        }
        res.pop_back();
        return res;
    }
};