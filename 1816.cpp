#include<bits/stdc++.h>

using namespace std;

class Solution {
public: 
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word;
        vector<string> words;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        string result = "";
        for (int i = 0; i < k; i++) {
            if (i > 0) result += " ";  
            result += words[i];
        }
        
        return result;
    }
};