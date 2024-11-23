#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int len = 0;
        bool has_odd = false;

        for (auto [ch, cnt] : freq) {
            if (cnt % 2 == 0) len += cnt;
            else {
                len += cnt - 1;
                has_odd = true;
            }
        }

        if (has_odd) len++;

        return len;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s);
}