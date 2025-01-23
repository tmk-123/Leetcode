#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> freq; 
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            freq[s[end]]++; 

            while (freq[s[end]] > 2) {
                freq[s[start]]--; 
                if (freq[s[start]] == 0) freq.erase(s[start]); 
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
int main() {
    Solution sol;
    cout << sol.maximumLengthSubstring("aaaa");
}