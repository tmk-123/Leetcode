#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        string digits, letters;
        for (char &c : s) {
            if (isdigit(c)) digits += c;
            else letters += c;
        }

        int a = letters.size(), b = digits.size();
        if (abs(a - b) > 1) return "";

        string res;
        int i = 0;
        while (i < min(a, b)) {
            res += letters[i];
            res += digits[i];
            i++;
        }

        if (a > b) res += letters[i];
        else if (a < b) res = digits[i] + res;
    
        return res;
    }
};