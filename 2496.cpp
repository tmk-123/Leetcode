#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxVal = INT_MIN;
        for (string s : strs) {
            bool foundStr = false;
            for (char c : s) {
                if (!isdigit(c)) {
                    foundStr = true;
                }
            }
            int len = s.length();
            if (foundStr) maxVal = max(maxVal, len);
            else maxVal = max(maxVal, stoi(s));
        }
        return maxVal;
    }
};