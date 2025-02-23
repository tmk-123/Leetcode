#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<int, int> m1, m2;
        for (char c : word1) {
            m1[c]++;
        }
        for (char c : word2) {
            m2[c]++;
        }

        int maxDiff = INT_MIN;
        for (char c = 'a'; c <= 'z'; c++) {
            maxDiff = max(maxDiff, abs(m1[c] - m2[c]));
        }
        if (maxDiff <= 3) return true;
        return false;
    }
};