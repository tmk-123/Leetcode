#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> Set;
        for (char c : s) Set.insert(c);

        char maxLetter = 'A' - 1;
        for (char c : Set) {
            if ('A' <= c && c <= 'Z' && Set.find(c + 'a' - 'A') != Set.end()) maxLetter = max(maxLetter, c);
        }
        if (maxLetter == 'A' - 1) return "";
        return string(1, maxLetter);
    }
};