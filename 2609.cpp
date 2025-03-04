#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxLen = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                cnt0++;
                cnt1 = 0;
            } 
            else {
                cnt1++;
                maxLen = max(maxLen, 2 * min(cnt0, cnt1));
                if (i < s.length() - 1 && s[i + 1] == '0') cnt0 = 0;
            }
        }
        return maxLen;
    }
};