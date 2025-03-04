#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        for (char c = '9'; c >= '0'; c--) {
            string s = string(3, c);
            if (num.find(s) != string::npos) return s;
        }
        return "";
    }
};