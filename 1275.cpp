#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        unordered_set<string> X, O;
        int cnt = 0;
        for (auto v : moves) {
            string s;
            if (v[0] == 0) s = "0" + to_string(v[1]);
            else s = to_string(v[0] * 10 + v[1]);

            if (cnt % 2 == 0) {
                X.insert(s);
            }
            else O.insert(s);
            cnt++;
        }

        if ( (X.find("00") != X.end() && X.find("11") != X.end() && X.find("22") != X.end()) || 
        X.find("00") != X.end() && X.find("01") != X.end() && X.find("02") != X.end() ||
        X.find("10") != X.end() && X.find("11") != X.end() && X.find("12") != X.end() ||
        X.find("20") != X.end() && X.find("21") != X.end() && X.find("22") != X.end() ||
        X.find("00") != X.end() && X.find("10") != X.end() && X.find("20") != X.end() ||
        X.find("01") != X.end() && X.find("11") != X.end() && X.find("21") != X.end() ||
        X.find("02") != X.end() && X.find("12") != X.end() && X.find("22") != X.end() ||
        X.find("20") != X.end() && X.find("11") != X.end() && X.find("02") != X.end()) return "A";

        if ( (O.find("00") != O.end() && O.find("11") != O.end() && O.find("22") != O.end()) || 
        O.find("00") != O.end() && O.find("01") != O.end() && O.find("02") != O.end() ||
        O.find("10") != O.end() && O.find("11") != O.end() && O.find("12") != O.end() ||
        O.find("20") != O.end() && O.find("21") != O.end() && O.find("22") != O.end() ||
        O.find("00") != O.end() && O.find("10") != O.end() && O.find("20") != O.end() ||
        O.find("01") != O.end() && O.find("11") != O.end() && O.find("21") != O.end() ||
        O.find("02") != O.end() && O.find("12") != O.end() && O.find("22") != O.end() ||
        O.find("20") != O.end() && O.find("11") != O.end() && O.find("02") != O.end()) return "B";
        if (cnt == 9) return "Draw";
        return "Pending";
    }
}; 