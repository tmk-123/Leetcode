#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        for (char c : magazine) letters[c]++;

        for (char c : ransomNote) {
            letters[c]--;
            if (letters[c] < 0) return false;
        }
        return true;
    }
};