#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> startMask;

        for (string& word : startWords) {
            int mask = 0;
            for (char& c : word) {
                mask |= 1 << (c - 'a');
            } 
            startMask.insert(mask);
        }

        int cnt = 0;

        for (string& word : targetWords) {
            int targetMask = 0;
            for (char c : word) targetMask |= 1 << (c - 'a');
            
            for (char c : word) {
                int removedMask = targetMask ^ (1 << (c - 'a'));
                if (startMask.count(removedMask)) {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};