#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int power = 1;
        int cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
                power = max(power, cnt);
            }
            else cnt = 1;
        }
        return power;
    }
};