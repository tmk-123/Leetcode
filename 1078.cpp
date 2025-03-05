#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words, result;
        stringstream ss(text);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        for (size_t i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }
        
        return result;
    }
};