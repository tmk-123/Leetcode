#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int n : arr) freq[n]++;

        unordered_map<int, int> numberFreq;
        for (auto [n, f] : freq) {
            numberFreq[f]++;
            if (numberFreq[f] > 1) return false;
        }
        return true;
    }
};