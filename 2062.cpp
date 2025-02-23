#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int cnt = 0;

        for (int left = 0; left < n; left++) {
            unordered_map<int, int> freq;
            int vowel = 0;

            for (int right = left; right < n; right++) {
                char c = word[right];
                if (string("aeiou").find(c) == string::npos) break;

                if (++freq[c] == 1) vowel++;
                if (vowel == 5) cnt++; 
            }
        }

        return cnt;
    }
};