#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        string s1 = p.substr(0, p.find("*"));
        string s2 = p.substr(p.find("*") + 1);

        if (s1 == "" && s2 == "") return true;
        if (s1 == "") {
            if (s.find(s2) != string::npos) return true;
            return false;
        }
        if (s2 == "") {
            if (s.find(s1) != string::npos) return true;
            return false;
        }

        int n1 = -1, n2 = -1;
        if (s.find(s1) != string::npos) n1 = s.find(s1);
        if (s.rfind(s2) != string::npos) n2 = s.rfind(s2);

        if (n1 == -1 || n2 == -1) return false;
        if (n1 + s1.length() <= n2) return true;
        return false;
    }
};