#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }
        
        for (auto x : freq) {
            // thử xóa
            freq[x.first]--;
            unordered_set<int> freqSet;
            for (auto f : freq) {
                if (f.second > 0) {
                    freqSet.insert(f.second);
                }
            }
            if (freqSet.size() == 1) return true;
            freq[x.first]++;
        }

        return false;
    }   
};

int main() {
    Solution sol;
    cout << sol.equalFrequency("abcc");
}