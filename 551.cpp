#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') cnt++;
            if (2 <= i && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') return false;
        }
        if (cnt >= 2) return false;
        return true;
    }
};  