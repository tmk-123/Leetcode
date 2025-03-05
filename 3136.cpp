#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false; 
    
        bool hasVowel = false, hasConsonant = false;
        
        for (char c : word) {
            if (!(isalpha(c) || isdigit(c))) return false; 
            
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                hasVowel = true;
            } else if (isalpha(c)) { 
                hasConsonant = true;
            }
        }
        
        return hasVowel && hasConsonant;
    }
};