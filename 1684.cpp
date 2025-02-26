#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int maskAllowed = 0;
        
        for (char c : allowed) maskAllowed |= (1 << (c - 'a'));

        int cnt = 0;
        for (string word : words) {
            int maskWord = 0;
            for (char c : word) {
                maskWord |= (1 << (c - 'a'));
            }

            if ((maskWord & maskAllowed) == maskWord) cnt++;
        }
        
        return cnt;
    }
};