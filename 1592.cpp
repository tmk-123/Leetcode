#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        string s;
        int totalSpaces = 0;
        vector<string> v;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                if (s != "") v.push_back(s);
                s = "";
                totalSpaces++;
            }
            else {
                s += text[i];
            }
        }
        if (s != "") v.push_back(s);

        if (v.size() == 1) return v[0] + string(totalSpaces, ' ');
        
        int n = totalSpaces / (v.size() - 1);
        string res = v[0];
        for (int i = 1; i < v.size(); i++) {
            res += string(n, ' ');
            res += v[i];
        }

        int x = totalSpaces - n * (v.size() - 1);
        res += string(x, ' ');
        return res;
    }
};