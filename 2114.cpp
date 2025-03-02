#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxLen = INT_MIN;
        for (string s : sentences) {
            stringstream ss(s);
            string word;
            int cnt = 0;
            while (ss >> word) {
                cnt++;
            }
            maxLen = max(maxLen, cnt);
        }
        return maxLen;
    }
};      