#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                if (freq[s[j]] > 2) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
int main() {
    Solution sol;
    cout << sol.maximumLengthSubstring("aaaa");
}