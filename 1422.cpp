#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros(s.length());
        vector<int> ones(s.length());
        
        int n1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') n1++;
            zeros[i] = n1;
        }

        int n2 = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '1') n2++;
            ones[i] = n2;
        }

        int scores = INT_MIN;
        for (int i = 0; i < s.length() - 1; i++) {
            scores = max(scores, zeros[i] + ones[i + 1]);
        }
        return scores;
    }
};