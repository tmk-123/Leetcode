#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (string& word : words) count[word]++;
        
        int len = 0;
        bool hasCentral = false;

        for (auto& [word, freq] : count) {
            string rev(word.rbegin(), word.rend());
            if (word != rev) {
                if (count.find(rev) != count.end()) {
                    len += min(freq, count[rev]) * 4;
                    count[rev] = 0;
                    count[word] = 0;
                }   
            }
            else {
                len += (freq / 2) * 4;
                if (freq % 2 == 1) hasCentral = true;
            }
        }

        if (hasCentral) len += 2;
        return len;
    }
};