#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> freq;
        int cnt = 0;

        for (string &word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }
            
            // word này ghép mới các word còn lại
            cnt += freq[mask];
            freq[mask]++;
        }

        return cnt;
    }
};