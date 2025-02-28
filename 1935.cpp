#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> Set;
        for (char c : brokenLetters) Set.insert(c);

        stringstream ss(text);
        string word;
        int fullWord = 0, notFullWord = 0;
        while (ss >> word) {
            for (char c : word) {
                if (Set.find(c) != Set.end()) {
                    notFullWord++;
                    break;
                }
            }
            fullWord++;
        }

        return fullWord - notFullWord;
    }
};