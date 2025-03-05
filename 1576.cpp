#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') {
                for (int c = 'a'; c <= 'z'; c++) {
                    if (i == 0) {
                        if (c != s[i + 1]) {
                            s[i] = c;
                            break;
                        } 
                    }
                    else if (i == s.length() - 1) {
                        if (c != s[i - 1]) {
                            s[i] = c;
                            break;
                        }
                    }
                    else {
                        if (c != s[i - 1] && c != s[i + 1]) {
                            s[i] = c;
                            break;
                        }
                    }
                }

            }
        }
        return s;
    }
};