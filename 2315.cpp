#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int cnt1 = 0, cnt2 = 0, total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|') {
                cnt1++;
                if (cnt1 % 2 == 1) {
                    total += cnt2;
                }
                cnt2 = 0;
            }
            if (s[i] == '*') cnt2++;
        }   

        return total + cnt2;
    }
};