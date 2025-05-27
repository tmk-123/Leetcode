#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string s) {
        int i = 0;
        int cntA = 0, cntB = 0;
        while (i < s.size()) {
            if (s[i] == 'A') {
                int cnt = 0;
                while (i < s.size() && s[i] == 'A') {
                    cnt++;
                    i++;
                }
                if (cnt > 2) cntA += cnt - 2;
            }
            else {
                int cnt = 0;
                while (i < s.size() && s[i] == 'B') {
                    cnt++;
                    i++;
                }
                if (cnt > 2) cntB += cnt - 2;
            }
        }

        return cntA > cntB;
    }
};