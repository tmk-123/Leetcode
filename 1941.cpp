#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        
        int maxCount = 0;
        for (char c : s) {
            freq[c]++;
            maxCount = max(maxCount, freq[c]);
        }

        for (auto x : freq) {
            if (x.second != maxCount) return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    cout << sol.areOccurrencesEqual("aaabbb");
}