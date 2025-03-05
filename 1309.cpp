#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        for (int i = s.length() - 1; i >= 0; ) {
            if (s[i] == '#') {
                int n = (s[i - 2] - '0') * 10 + s[i - 1] - '0'; 
                res = string(1, 'j' + n - 10) + res;
                i -= 3;
            }
            else {
                res = string(1, 'a' + s[i] - '1') + res;
                i--;
            }
        } 
        return res;
    }
};