#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        stringstream ss(s1);
        string word;
        while (ss >> word) {
            m[word]++;
        }
        stringstream s(s2); 
        while (s >> word) {
            m[word]++;
        }
        
        vector<string> v;
        for (auto& [word, freq] : m) {
            if (freq == 1) v.push_back(word); 
        }
        return v;
    }
};