#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "0";
        for (int i = 0; i < number.length(); i++) {
            if (number[i] == digit) {
                string a = number.substr(0, i);
                string b = number.substr(i + 1);
                string t = a + b;
                res = max(res, t);
            }
        }
        return res;
    }
};