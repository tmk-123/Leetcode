#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> freq;
        int n = words.size();

        for (string word : words) {
            for (char c : word) {
                freq[c]++;
            }
        }

        for (auto& [ch, count] : freq) {
            if (count % n != 0) {
                return false;
            }
        }

        return true;
    }
};